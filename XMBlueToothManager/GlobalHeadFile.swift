//
//  GlobalHeadFile.swift
//  BluetoothBand
//
//  Created by 王续敏 on 16/11/8.
//  Copyright © 2016年 JIAQISHIDAI. All rights reserved.
//

import UIKit

let KSCREEN_WIDTH = UIScreen.main.bounds.size.width
let KSCREEN_HEIGHT = UIScreen.main.bounds.size.height
func XMLog<T>(message : T?,file: String = #file,methodName: String = #function, lineNumber: Int = #line){
    #if DEBUG
        let fileName = NSString.init(string: (file as String)).lastPathComponent
        let line = String.init(format: "第%d行", lineNumber)
        let name = "======>"
        let date = NSDate()
        let timeFormatter = DateFormatter()
        timeFormatter.dateFormat = "yyy-MM-dd 'at' HH:mm:ss.SSS"
        let strNowTime = timeFormatter.string(from: date as Date) as String
        print("[\(strNowTime)][\(fileName)\(line)]\(methodName)\(name)\(message)")
    #endif
}

