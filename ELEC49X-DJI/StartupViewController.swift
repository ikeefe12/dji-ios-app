//
//  StartupViewController.swift
//  DJISDKSwiftDemo
//
//  Created by DJI on 11/13/15.
//  Copyright © 2015 DJI. All rights reserved.
//

import UIKit
import DJISDK

class StartupViewController: UIViewController {

    weak var appDelegate: AppDelegate! = UIApplication.shared.delegate as? AppDelegate
    
    @IBOutlet weak var productConnectionStatus: UILabel!
    @IBOutlet weak var productModel: UILabel!
    @IBOutlet weak var openComponents: UIButton!
    @IBOutlet weak var sdkVersionLabel: UILabel!
    @IBOutlet weak var bridgeModeLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.resetUI()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        guard let connectedKey = DJIProductKey(param: DJIParamConnection) else {
            NSLog("Error creating the connectedKey")
            return;
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 1) { 
            DJISDKManager.keyManager()?.startListeningForChanges(on: connectedKey, withListener: self, andUpdate: { (oldValue: DJIKeyedValue?, newValue : DJIKeyedValue?) in
                if newValue != nil {
                    if newValue!.boolValue {
                        // At this point, a product is connected so we can show it.
                        
                        // UI goes on MT.
                        DispatchQueue.main.async {
                            self.productConnected()
                        }
                    }
                }
            })
            DJISDKManager.keyManager()?.getValueFor(connectedKey, withCompletion: { (value:DJIKeyedValue?, error:Error?) in
                if let unwrappedValue = value {
                    if unwrappedValue.boolValue {
                        // UI goes on MT.
                        DispatchQueue.main.async {
                            self.productConnected()
                        }
                    }
                }
            })
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        DJISDKManager.keyManager()?.stopAllListening(ofListeners: self)
    }
    
    
    func resetUI() {
        self.title = "Drone Hub"
        self.sdkVersionLabel.text = "DJI SDK Version: \(DJISDKManager.sdkVersion())"
        self.openComponents.isEnabled = true; //FIXME: set it back to false
        self.productModel.isHidden = true
        self.bridgeModeLabel.isHidden = !self.appDelegate.productCommunicationManager.enableBridgeMode
        
        if self.appDelegate.productCommunicationManager.enableBridgeMode {
            self.bridgeModeLabel.text = "Bridge: \(self.appDelegate.productCommunicationManager.bridgeAppIP)"
        }
    }
    
    func showAlert(_ msg: String?) {
        // create the alert
        let alert = UIAlertController(title: "", message: msg, preferredStyle: UIAlertController.Style.alert)
        // add the actions (buttons)
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: nil))
        // show the alert
        self.present(alert, animated: true, completion: nil)
    }
    
    // MARK : Product connection UI changes
    
    func productConnected() {
        guard let newProduct = DJISDKManager.product() else {
            NSLog("Product is connected but DJISDKManager.product is nil -> something is wrong")
            return;
        }

        //Updates the product's model
        self.productModel.text = "Model: \((newProduct.model)!)"
        self.productModel.isHidden = false
        
        //Updates the product's connection status
        self.productConnectionStatus.text = "Status: Product Connected"
        
        self.openComponents.isEnabled = true;
        self.openComponents.alpha = 1.0;
        NSLog("Product Connected")
    }
    
    func productDisconnected() {
        self.productConnectionStatus.text = "Status: No Product Connected"

        self.openComponents.isEnabled = true;
        self.openComponents.alpha = 0.8;
        NSLog("Product Disconnected")
    }
    
}





