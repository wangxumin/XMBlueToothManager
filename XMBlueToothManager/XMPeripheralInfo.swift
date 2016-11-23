//
//  JQPeripheralInfo.swift
//  BluetoothBand
//
//  Created by 王续敏 on 16/11/12.
//  Copyright © 2016年 wangxumin. All rights reserved.
//

import UIKit

class XMPeripheralInfo: NSObject {
    
    var serviceUUID = CBUUID()
    var characteristics = NSMutableArray()
    
    override init() {

        self.characteristics = NSMutableArray.init()
        
    }
    
}
