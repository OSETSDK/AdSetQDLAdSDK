//
//  AdSetQDLNativeAd.h
//  AdSetQDLAdSDK
//
//  Created by qusy on 2023/12/28.
//

#import <UIKit/UIKit.h>

#import <AdSetQDLAdSDK/AdSetQDLAdMeta.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDLNativeAdDelegate;

@interface AdSetQDLNativeAd : NSObject

@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
@property (nonatomic, strong, readonly, nullable) AdSetQDLAdMeta *meta;
@property (nonatomic, weak) UIViewController *viewController;

@property (nonatomic, weak) id<AdSetQDLNativeAdDelegate> delegate;

@property (nonatomic, strong, readonly, nullable) UIView *videoView;

/// 服务端竞价返回参数（仅在服务端竞价时有效，需要在 loadAdData 之前设置）
@property (nonatomic, strong) NSString *adm;

/// 初始化
/// @param slotID  栏位id
- (instancetype)initWithSlot:(NSString *)slotID;

/// 加载广告
- (void)loadAdData;

/// 注册可点击区域
/// @param containerView :  requried  广告展示区域
/// @param clickableViews : optional  其他可点击区域
- (void)registerContainer:(__kindof UIView *)containerView withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;

/// Unregister ad view from the native ad.
- (void)unregisterView;

/// 竞价成功
/// - Parameter auctionSecondPrice: 竞价第二名价格，单位是分
- (void)winNotice:(NSInteger)auctionSecondPrice;

/**
 竞价失败
 @param auctionPrice 胜出者价格，单位分
 @param winBidder 胜出者对应媒体
        如果需要扩展，可以直接传入自定义字符串。
 @param lossReason 竞价失败原因
        如果需要扩展，可以直接传入自定义的字符串（建议字符串为 >1000 的数字）
 */
- (void)lossNotice:(NSInteger)auctionPrice
        lossReason:(QMLossReason * _Nullable)lossReason
         winBidder:(QMWinBidder * _Nullable)winBidder;

/// 是否有效 YES: 有效 NO: 无效
- (BOOL)isValid;

/// 获取服务端竞价 token
- (NSString *)getBiddingToken;

@end

@protocol AdSetQDLNativeAdDelegate <NSObject>

@optional

/// 自渲染广告加载成功
- (void)adSetQDL_nativeAdLoadSuccess:(AdSetQDLNativeAd *)nativeAd;

/// 自渲染广告加载失败
- (void)adSetQDL_nativeAdLoadFail:(AdSetQDLNativeAd *)nativeAd error:(NSError *)error;

/// 自渲染广告曝光
- (void)adSetQDL_nativeAdDidShow:(AdSetQDLNativeAd *)nativeAd;

/// 自渲染广告点击
- (void)adSetQDL_nativeAdDidClick:(AdSetQDLNativeAd *)nativeAd;

/// 自渲染落地页关闭
- (void)adSetQDL_nativeAdDidCloseOtherController:(AdSetQDLNativeAd *)nativeAd;

/// 自渲染视频播放开始
- (void)adSetQDL_nativeAdDidStart:(AdSetQDLNativeAd *)nativeAd;

/// 自渲染视频播放暂停
- (void)adSetQDL_nativeAdDidPause:(AdSetQDLNativeAd *)nativeAd;

/// 自渲染视频播放继续
- (void)adSetQDL_nativeAdDidResume:(AdSetQDLNativeAd *)nativeAd;

/// 自渲染视频播放完成
- (void)adSetQDL_nativeAdVideoDidPlayComplection:(AdSetQDLNativeAd *)nativeAd;

/// 自渲染视频播放异常
- (void)adSetQDL_nativeAdVideoDidPlayFinished:(AdSetQDLNativeAd *)nativeAd didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
