//
//  CameraFPVViewController.swift
//  DJISDKSwiftDemo
//
//  Created by DJI on 2019/1/15.
//  Copyright © 2019 DJI. All rights reserved.
//

import UIKit
import DJISDK

class CameraFPVViewController: UIViewController {
    @IBOutlet weak var irStatus: UILabel!
    @IBOutlet weak var trackingStatus: UILabel!
    @IBOutlet weak var irToggle: UISwitch!
    @IBOutlet weak var trackingToggle: UISwitch!
    @IBOutlet weak var emergencyLand: UIButton!
    @IBOutlet weak var fpvView: UIView!
    @IBOutlet weak var test: UIButton!

    
    var adapter: VideoPreviewerAdapter?
    var needToSetMode = false
    var heatSeek: HeatSeeking?
        
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.resetUI()
        
        heatSeek = HeatSeeking()
        
        let camera = fetchCamera()
        camera?.delegate = self
        
        needToSetMode = true
        
        DJIVideoPreviewer.instance()?.start()
        
        adapter = VideoPreviewerAdapter.init()
        adapter?.start()
        
        if camera?.displayName == DJICameraDisplayNameMavic2ZoomCamera ||
            camera?.displayName == DJICameraDisplayNameDJIMini2Camera ||
            camera?.displayName == DJICameraDisplayNameMavicAir2Camera ||
            camera?.displayName == DJICameraDisplayNameDJIAir2SCamera ||
            camera?.displayName == DJICameraDisplayNameMavic2ProCamera {
            adapter?.setupFrameControlHandler()
        }
    }
    
    func resetUI() {
        // set state of labels
        self.irStatus.text = "IR Disabled"
        self.trackingStatus.text = "Tracking Disabled"
        // Set state of switches
        self.irToggle.setOn(false, animated: true)
        self.irToggle.tintColor = UIColor.red
        self.irToggle.onTintColor = UIColor.green
        self.irToggle.addTarget(self, action: #selector(irStateChanged(_:)), for: .valueChanged)
        self.trackingToggle.setOn(false, animated: true)
        self.trackingToggle.isEnabled = false
        self.trackingToggle.tintColor = UIColor.red
        self.trackingToggle.onTintColor = UIColor.green
        self.trackingToggle.addTarget(self, action: #selector(trackingStateChanged(_:)), for: .valueChanged)
        // Set state of emergency land
        self.emergencyLand.setTitle("Emergency Land", for: .normal)
        // self.emergencyLand.tintColor = UIColor.red
        self.emergencyLand.addTarget(self, action: #selector(emergencyLandAction(_:)), for: .touchUpInside)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        DJIVideoPreviewer.instance()?.setView(fpvView)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        // Call unSetView during exiting to release the memory.
        DJIVideoPreviewer.instance()?.unSetView()
        
        if adapter != nil {
            adapter?.stop()
            adapter = nil
        }
    }
    // add button
    // update vars to what
    // 
    
    @objc func irStateChanged(_ sender: UISwitch) {
        if sender.isOn {
            self.irStatus.text = "IR Enabled"
            self.trackingToggle.isEnabled = true
            // START/ DATA AND DISPLAY THREADS
            heatSeek?.enableThermalDataAndDisplay(view: self.view)
            // heatSeek?.dispData(view: self.view, frame: [[0]])
        } else {
            self.irStatus.text = "IR Disabled"
            self.trackingToggle.setOn(false, animated: true)
            self.trackingToggle.isEnabled = false
            // STOP TRACKING THREAD (if started)
            heatSeek?.stopTracking()
            // STOP DATA AND DISPLAY THREADS
            heatSeek?.disableThermalDataAndDisplay()
        }
    }
    
    @objc func trackingStateChanged(_ sender: UISwitch) {
        if sender.isOn {
            self.trackingStatus.text = "Tracking Enabled"
            // START TRACKING THREAD
            heatSeek?.startTracking()
        } else {
            // STOP TRACKING THREAD
            self.trackingStatus.text = "Tracking Disabled"
            heatSeek?.stopTracking()
        }
    }
    
    @objc func emergencyLandAction(_ sender: UIButton) {
        // EMERGENCY LAND
        sender.isEnabled = false
        self.irToggle.setOn(false, animated: true)
        self.irToggle.isEnabled = false
        heatSeek?.disableThermalDataAndDisplay()
        self.trackingToggle.setOn(false, animated: true)
        self.trackingToggle.isEnabled = false
        heatSeek?.stopTracking()
        print("Emergency Land")
        heatSeek?.emergencyLanding()
    }
    
    @objc func testRight(_ sender: UIButton) {
        // test right
        // set pitch = 0.5, roll = 0 (or somethign)
        // sleep 5 seconds
        // semd it baclk
        print("Test Right")
        heatSeek?.testRight()
    }
}

/**
 *  DJICamera will send the live stream only when the mode is in DJICameraModeShootPhoto or DJICameraModeRecordVideo. Therefore, in order
 *  to demonstrate the FPV (first person view), we need to switch to mode to one of them.
 */
extension CameraFPVViewController: DJICameraDelegate {
    func camera(_ camera: DJICamera, didUpdate systemState: DJICameraSystemState) {
        if systemState.mode != .recordVideo && systemState.mode != .shootPhoto {
            return
        }
        if needToSetMode == false {
            return
        }
        needToSetMode = false
        self.setCameraMode(cameraMode: .shootPhoto)
        
    }
}

extension CameraFPVViewController {
    fileprivate func fetchCamera() -> DJICamera? {
        guard let product = DJISDKManager.product() else {
            return nil
        }
        
        if product is DJIAircraft || product is DJIHandheld {
            return product.camera
        }
        return nil
    }
    
    fileprivate func setCameraMode(cameraMode: DJICameraMode = .shootPhoto) {
        var flatMode: DJIFlatCameraMode = .photoSingle
        let camera = self.fetchCamera()
        if camera?.isFlatCameraModeSupported() == true {
            NSLog("Flat camera mode detected")
            switch cameraMode {
            case .shootPhoto:
                flatMode = .photoSingle
            case .recordVideo:
                flatMode = .videoNormal
            default:
                flatMode = .photoSingle
            }
            camera?.setFlatMode(flatMode, withCompletion: { [weak self] (error: Error?) in
                if error != nil {
                    self?.needToSetMode = true
                    NSLog("Error set camera flat mode photo/video");
                }
            })
            } else {
                camera?.setMode(cameraMode, withCompletion: {[weak self] (error: Error?) in
                    if error != nil {
                        self?.needToSetMode = true
                        NSLog("Error set mode photo/video");
                    }
                })
            }
     }
}
