//
//  AdSetQDLFeedAdsManager.h
//  AdSetQDLAdSDK
//
//  Created by Donnie on 2026/6/5.
//

#import <Foundation/Foundation.h>

#import <AdSetQDLAdSDK/AdSetQDLFeedAd.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDLFeedAdsManagerDelegate;

@interface AdSetQDLFeedAdsManager : NSObject

@property (nonatomic, strong, readonly, nullable) NSArray<AdSetQDLFeedAd *> *data;
@property (nonatomic, weak, nullable) id<AdSetQDLFeedAdsManagerDelegate> delegate;

/// 自定义尺寸
@property (nonatomic, assign) CGSize customSize;

// 初始化
// @param slotID 栏位id
- (instancetype)initWithSlot:(NSString *)slotID;

// 加载广告
// @param count 广告数量（最小为 1）
- (void)loadAdDataWithCount:(NSInteger)count;

@end

@protocol AdSetQDLFeedAdsManagerDelegate <NSObject>

@optional

- (void)adSetQDL_feedAdsManagerLoadSuccess:(AdSetQDLFeedAdsManager *)adsManager feedAds:(NSArray<AdSetQDLFeedAd *> *_Nullable)feedAdsArray;

- (void)adSetQDL_feedAdsManagerLoadFail:(AdSetQDLFeedAdsManager *)adsManager error:(NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
