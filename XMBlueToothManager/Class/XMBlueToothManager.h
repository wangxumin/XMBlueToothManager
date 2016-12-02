//
//  XMBlueToothManager.h
//  XMBlueToothManager
//
//  Created by 王续敏 on 16/11/23.
//  Copyright © 2016年 wangxumin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BabyBluetooth.h"
#import "SVProgressHUD.h"

#define XMSERVICEBLOCK (CBPeripheral *peripheral, NSError *error)
#define XMCHARCTICBLOCK (CBPeripheral *peripheral, CBService *service, NSError *error)
#define XMVALUEFORCHARCTIC (CBPeripheral *peripheral, CBCharacteristic *characteristics, NSError *error)
#define XMDISCOVERDSCRIPFORCH (CBPeripheral *peripheral, CBCharacteristic *characteristic, NSError *error)
#define XMREADVALUEFORDES (CBPeripheral *peripheral, CBDescriptor *descriptor, NSError *error)
/**
 扫描到设备
 
 @param central 外设中心
 @param peripheral 外设
 @param advertisementData advertisementData
 @param RSSI RSSI
 */
typedef void(^XMPeripheralsBlock)(CBCentralManager *central, CBPeripheral *peripheral, NSDictionary *advertisementData, NSNumber *RSSI);

/**
 发现设备服务
 
 @param peripheral 外设
 @param error error
 */
typedef void(^XMDiscoverServices)XMSERVICEBLOCK;

/**
 发现设备的Characteristics
 
 @param peripheral peripheral
 @param service service
 @param error error
 */
typedef void(^XMDiscoverCharacteristics)XMCHARCTICBLOCK;

/**
 读取到的特征值
 
 @param peripheral peripheral
 @param characteristics characteristics
 @param error error
 */
typedef void(^XMReadValueForCharacteristic)XMVALUEFORCHARCTIC;

/**
 读取到特征描述
 
 @param peripheral peripheral
 @param characteristic characteristic
 @param error error
 */
typedef void(^XMDiscoverDescriptorsForCharacteristic)XMDISCOVERDSCRIPFORCH;

/**
 读取Descriptor
 
 @param peripheral peripheral
 @param descriptor descriptor
 @param error error
 */
typedef void(^XMReadValueForDescriptors)XMREADVALUEFORDES;

/**
 设置查找设备的过滤器
 
 @param peripheralName peripheralName
 @param advertisementData advertisementData
 @param RSSI RSSI
 */
typedef BOOL(^XMsetFilterOnDiscoverPeripherals)(NSString *peripheralName, NSDictionary *advertisementData, NSNumber *RSSI);

/**
 链接成功与否
 
 @param state state
 */
typedef void(^XMConnectStateBlock)(BOOL state);

/**
 断开连接
 
 @param central central
 @param peripheral peripheral
 @param error error
 */
typedef void(^XMDisconnectAtChannel)(CBCentralManager *central, CBPeripheral *peripheral, NSError *error);

/**
 发现服务
 */
typedef void(^XMDiscoverServicesAtChannel)XMSERVICEBLOCK;

/**
 发现特征
 */
typedef void(^XMDiscoverCharacteristicsAtChannel)XMCHARCTICBLOCK;

/**
 读取到service的特征值
 */
typedef void(^XMReadValueForCharacteristicAtChannel)XMVALUEFORCHARCTIC;

/**
 发现特征描述
 */
typedef void(^XMDiscoverDescriptorsForCharacteristicAtChannel)XMDISCOVERDSCRIPFORCH;

/**
 读取特定频道的描述信息
 */
typedef void(^XMReadValueForDescriptorsAtChannel)XMREADVALUEFORDES;
typedef void(^XMReadRSSI)(NSNumber *RSSI, NSError *error);
typedef void(^XMPeripheralManagerDidUpdateState)(CBPeripheralManager *peripheral);
typedef void(^XMDidReadRSSIAtChannel)(NSNumber *RSSI, NSError *error);
typedef void(^XMBlockOnDisconnectAtChannel)(CBCentralManager *central, CBPeripheral *peripheral, NSError *error);
typedef void(^XMDidUpdateNotificationStateForCharacteristicAtChannel)(CBCharacteristic *characteristic, NSError *error);
typedef void(^XMDidWriteValueForCharacteristicAtChannel)(CBCharacteristic *characteristic, NSError *error);
@protocol XMBlueToothDelegate <NSObject>


@end

@interface XMBlueToothManager : NSObject


@property (nonatomic , weak) id<XMBlueToothDelegate>delegate;
@property (nonatomic , strong) NSMutableArray *peripherals;//查找到的所有的外设
@property (nonatomic , copy) XMDidReadRSSIAtChannel readRSSIAtChannel;
@property (nonatomic , copy) XMBlockOnDisconnectAtChannel disconnectAtChannel;
@property (nonatomic , copy) XMDidUpdateNotificationStateForCharacteristicAtChannel notiUpdateAtChannel;
@property (nonatomic , copy) XMDidWriteValueForCharacteristicAtChannel didWriteData;
/**
 单例初始化
 */
+ (XMBlueToothManager *)defaultManager;

/**
 取消之前的连接
 */
- (void)cancleAllConnect;

/**
 开始扫描外设
 */
- (void)beginToScan;

/**
 扫描多久之后停止扫描
 
 @param time 限制时间(s)
 */
- (void)beginToScanWithLimitTime:(int)time;

/**
 停止扫描
 */
- (void)cancleScan;

/**
 扫描到外设的代理
 
 @param block block
 */
- (void)xm_discoverPeripherals:(XMPeripheralsBlock)block;

/**
 发现设备服务
 
 @param block block
 */
- (void)xm_discoverPeripheralService:(XMDiscoverServices)block;

/**
 发现Characteristic
 
 @param block block
 */
- (void)xm_discoverCharacteristics:(XMDiscoverCharacteristics)block;

/**
 读取特征值
 
 @param block block
 */
- (void)xm_readValueForCharacteristic:(XMReadValueForCharacteristic)block;

/**
 读取特征描述
 
 @param block block
 */
- (void)xm_discoverDescriptorsForCharacteristic:(XMDiscoverDescriptorsForCharacteristic)block;

/**
 读取Descriptors
 
 @param block block
 */
- (void)xm_readValueForDescriptors:(XMReadValueForDescriptors)block;

/**
 设置设备查找的过滤条件
 
 @param block block
 */
- (void)xm_setFilterOnDiscoverPeripherals:(XMsetFilterOnDiscoverPeripherals)block;

/**
 连接外设
 
 @param channel channel
 */
- (void)connectToPeripheralWithChannel:(NSString *)channel peripheral:(CBPeripheral *)peripheral;

/**
 连接成功与否
 
 @param block block
 */
- (void)xm_connectState:(XMConnectStateBlock)block;

/**
 断开连接失败的回调
 
 @param block block
 */
- (void)xm_disconnectAtChannelBlock:(XMDisconnectAtChannel)block;

/**
 发现服务
 
 @param block block
 */
- (void)xm_discoverServicesAtChannel:(XMDiscoverServicesAtChannel)block;

/**
 发现特征
 
 @param block block
 */
- (void)xm_xmDiscoverCharacteristicsAtChannel:(XMDiscoverCharacteristicsAtChannel)block;

/**
 读取特征值
 
 @param block block
 */
- (void)xm_readValueForCharacterAtChannel:(XMReadValueForCharacteristicAtChannel)block;

/**
 发现特定频道的特征描述
 
 @param block block
 */
- (void)xm_discoverDescriptorsForCharacteristicAtChannel:(XMDiscoverDescriptorsForCharacteristicAtChannel)block;

/**
 读取特定频道的特征描述
 
 @param block block
 */
- (void)xm_readValueForDescriptorsAtChannel:(XMReadValueForDescriptorsAtChannel)block;

/**
 读取RSSI
 
 @param block block
 */
- (void)xm_readRSSI:(XMReadRSSI)block;

/**
 外设状态更新
 
 @param block block
 */
- (void)xm_peripheralManagerDidUpdateState:(XMPeripheralManagerDidUpdateState)block;

/**
 添加断开重连的设备
 
 @param peripheral peripheral
 */
- (void)xm_addAutoReconnectPeripheral:(CBPeripheral *)peripheral;

/**
 读取特定频道的rssi
 
 @param block block
 */
- (void)xm_didReadRSSIAtChannel:(XMDidReadRSSIAtChannel)block;

/**
 读取详细信息
 
 @param channel chanel
 @param characteristic 当前的characteristic
 @param currPeripheral 当前的currPeripheral
 */
- (void)readDetailValueOfCharacteristicWithChannel:(NSString *)channel characteristic:(CBCharacteristic *)characteristic currPeripheral:(CBPeripheral *)currPeripheral;

/**
 外设断开连接的回调
 
 @param block block
 */
- (void)xm_blockOnDisconnectAtChannel:(XMBlockOnDisconnectAtChannel)block;

/**
 订阅状态发生改变
 
 @param block block
 */
- (void)xm_didUpdateNotificationStateForCharacteristicAtChannel:(XMDidUpdateNotificationStateForCharacteristicAtChannel)block;

/**
 写数据成功的回调
 
 @param block block
 */
- (void)xm_didWriteValueForCharacteristicAtChannel:(XMDidWriteValueForCharacteristicAtChannel)block;

/**
 给外设写入数据
 
 @param data data
 */
- (void)writeData:(NSData *)data ToPeripheral:(CBPeripheral *)peripheral forCharacteristic:(CBCharacteristic *)characteristic;

/**
 订阅数据
 
 @param peripheral peripheral
 @param characteristic characteristic
 */
- (void)xm_setNotifiyWithPeripheral:(CBPeripheral *)peripheral forCharacteristic:(CBCharacteristic *)characteristic block:(XMReadValueForCharacteristic)block;

/**
 发现当前连接的设备
 
 @return peripherals
 */
- (NSArray *)xmFindConnectedPeripherals;

/**
 取消订阅
 
 @param peripheral peripheral
 @param characteristic characteristic
 */
- (void)xm_cancleNotifyWith:(CBPeripheral *)peripheral characteristic:(CBCharacteristic *)characteristic;
@end
