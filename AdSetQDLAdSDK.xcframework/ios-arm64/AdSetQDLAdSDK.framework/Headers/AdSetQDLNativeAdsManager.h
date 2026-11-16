//
//  AdSetQDLNativeAdsManager.h
//  AdSetQDLAdSDK
//
//  Created by Donnie on 2026/6/25.
//

#import <Foundation/Foundation.h>

#import <AdSetQDLAdSDK/AdSetQDLNativeAd.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDLNativeAdsManagerDelegate;

@interface AdSetQDLNativeAdsManager : NSObject

@property (nonatomic, strong, readonly, nullable) NSArray<AdSetQDLNativeAd *> *data;
@property (nonatomic, weak, nullable) id<AdSetQDLNativeAdsManagerDelegate> delegate;

// 初始化
// @param slotID 栏位id
- (instancetype)initWithSlot:(NSString *)slotID;

// 加载广告
// @param count 广告数量（最小为 1）
- (void)loadAdDataWithCount:(NSInteger)count;

@end

@protocol AdSetQDLNativeAdsManagerDelegate <NSObject>

@optional

- (void)adSetQDL_nativeAdsManagerLoadSuccess:(AdSetQDLNativeAdsManager *)adsManager nativeAds:(NSArray<AdSetQDLNativeAd *> *_Nullable)nativeAdsArray;

- (void)adSetQDL_nativeAdsManagerLoadFail:(AdSetQDLNativeAdsManager *)adsManager error:(NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
