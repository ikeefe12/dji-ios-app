//
//  ConnectSensor.swift
//  
//
//  Created by Eva Blainey on 01.02.23.
//

import Foundation
import BlueSocket
import UIKit

let IP_ADDRESS = "192.168.0.120"
let PORT: UInt16 = 30444

func formatData(_ dataBinary: Data) -> [Int] {
    let hexString = dataBinary.map { String(format: "%02hhx", $0) }.joined()
    let numbers = (0..<hexString.count / 4).map {
        Int(String(hexString[hexString.index(hexString.startIndex, offsetBy: $0 * 4)..<hexString.index(hexString.startIndex, offsetBy: $0 * 4 + 4)]), radix: 16)!
    }
    return numbers
}

do {
    let clientSocket = try Socket.create(family: .inet, type: .datagram, proto: .udp)
    try clientSocket.connect(to: IP_ADDRESS, port: PORT)
    try clientSocket.write(from: "Bind HTPA series device".data(using: .utf8)!)
    let data = try clientSocket.read(into: 1024)
    print(String(data: data, encoding: .utf8)!)
    try clientSocket.write(from: "K".data(using: .utf8)!)
    var data = Data()
    for _ in 0..<14 {
        let newData = try clientSocket.read(into: 1400)
        data.append(newData)
    }
    let newData = try clientSocket.read(into: 560)
    data.append(newData)
    let grey16 = formatData(data)
    let grey16Array = grey16.map { UInt16($0) }
    let grey16Matrix = Array(stride(from: 0, to: grey16Array.count, by: 84))
        .map { Array(grey16Array[$0..<$0 + 84]) }
    let gray8Image = grey16Matrix.map {
        $0.map { UInt8(Double($0) / 65535.0 * 255.0) }
    }
    let infernoPalette = gray8Image.map { UIImage(cgImage: CIColorMap(gray8Image: $0).outputImage!) }
    infernoPalette.forEach { _ = $0.cgImage } // Force UIImage to render before saving to disk
} catch let error {
    print("Error: \(error)")
}
