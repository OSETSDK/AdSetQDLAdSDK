//
//  AdSetQDLInterstitialAd.h
//  AdSetQDLAdSDK
//
//  Created by qusy on 2023/12/28.
//

#import <UIKit/UIKit.h>
#import <AdSetQDLAdSDK/AdSetQDLAdMeta.h>

typedef NS_ENUM(NSUInteger, AdSetQDLInterstitialAdCloseType) {
    AdSetQDLInterstitialAdCloseTypeNormal = 0,
};

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDLInterstitialAdDelegate;

@interface AdSetQDLInterstitialAd : NSObject

@property (nonatomic, weak) id <AdSetQDLInterstitialAdDelegate> delegate;

/// 广告点击自动关闭
@property (nonatomic) BOOL adClickToCloseAutomatically;

/// 使用 controller present 落地页，默认使用广告 VC
@property (nonatomic, weak) UIViewController *viewController;

/// 广告物料
@property (nonatomic, strong) AdSetQDLAdMeta *meta;
/// 栏位id
@property (nonatomic, readonly, copy) NSString *slotID;

/// 服务端竞价返回参数（仅在服务端竞价时有效，需要在 loadAdData 之前设置）
@property (nonatomic, strong) NSString *adm;

/// 初始化
/// @param slotID  栏位id
- (nonnull instancetype)initWithSlot:(NSString *)slotID;

/// 加载广告
- (void)loadAdData;

/// 展示广告
- (void)showInterstitialViewInRootViewController:(UIViewController *)viewController;

/// 关闭插屏广告
- (void)closeInterstitialAd;

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
        lossReason:(QMLossReason  * _Nullable)lossReason
         winBidder:(QMWinBidder  * _Nullable)winBidder;

/// 是否有效 YES: 有效 NO: 无效
- (BOOL)isValid;

/// 获取服务端竞价 token
- (NSString *)getBiddingToken;

@end

@protocol AdSetQDLInterstitialAdDelegate <NSObject>

@optional

/// 插屏广告加载成功
- (void)adSetQDL_interstitialAdLoadSuccess:(AdSetQDLInterstitialAd *)interstitialAd;

/// 插屏广告加载失败
- (void)adSetQDL_interstitialAdLoadFail:(AdSetQDLInterstitialAd *)interstitialAd error:(NSError *)error;

/// 插屏广告曝光
- (void)adSetQDL_interstitialAdDidShow:(AdSetQDLInterstitialAd *)interstitialAd;

/// 插屏广告点击
- (void)adSetQDL_interstitialAdDidClick:(AdSetQDLInterstitialAd *)interstitialAd;

/// 插屏广告关闭
- (void)adSetQDL_interstitialAdDidClose:(AdSetQDLInterstitialAd *)interstitialAd closeType:(AdSetQDLInterstitialAdCloseType)type;

/// 插屏广告视频播放开始
- (void)adSetQDL_interstitialAdDidStart:(AdSetQDLInterstitialAd *)rewardedVideoAd;

/// 插屏广告视频播放暂停
- (void)adSetQDL_interstitialAdDidPause:(AdSetQDLInterstitialAd *)rewardedVideoAd;

/// 插屏广告视频播放继续
- (void)adSetQDL_interstitialAdDidResume:(AdSetQDLInterstitialAd *)rewardedVideoAd;

/// 插屏广告视频播放完成
- (void)adSetQDL_interstitialAdVideoDidPlayComplection:(AdSetQDLInterstitialAd *)interstitialAd;

/// 插屏广告视频播放异常
- (void)adSetQDL_interstitialAdVideoDidPlayFinished:(AdSetQDLInterstitialAd *)interstitialAd didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
