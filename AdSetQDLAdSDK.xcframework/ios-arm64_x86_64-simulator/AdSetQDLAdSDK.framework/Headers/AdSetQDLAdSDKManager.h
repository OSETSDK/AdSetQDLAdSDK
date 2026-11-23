//
//  AdSetQDLAdSDKManager.h
//  AdSetQDLAdSDK
//
//  Created by qusy on 2023/12/29.
//
//  1.9.5
//  19551.261123

#import <Foundation/Foundation.h>
#import <AdSetQDLAdSDK/AdSetQDLAdSDKConfiguration.h>

typedef NS_ENUM(NSUInteger, AdSetQDLAdSDKInitializationState) {
    AdSetQDLAdSDKInitializationStateNotReady = 0,
    AdSetQDLAdSDKInitializationStateReady = 1,
    AdSetQDLAdSDKInitializationStateFailed = 2
};

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface AdSetQDLAdSDKManager : NSObject

/// 版本号
+ (NSString *)sdkVersion;

/// 小版本号
+ (NSString *)shortSdkVersion;

/// QMCD
+ (NSArray *)qmcds;

/// The  initialization state
+ (AdSetQDLAdSDKInitializationState)sdkState;

/// 是否允许摇一摇/扭一扭（单设备纬度）
/// 默认：YES 允许
+ (void)setTwistSwitch:(BOOL)enabled;

/// 是否开启定位权限
/// 默认：YES 允许
+ (void)canUseLocation:(BOOL)isOpen;

/// The  initialization method
+ (void)setupSDKWith:(AdSetQDLAdSDKConfiguration *)config;

/// 初始化 SDK
+ (void)setupSDKWith:(AdSetQDLAdSDKConfiguration *)config completion:(void (^)(BOOL success, NSError *error))handler;

@end

NS_ASSUME_NONNULL_END
