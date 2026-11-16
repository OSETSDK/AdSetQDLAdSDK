//
//  AdSetQDLSplashAd.h
//  AdSetQDLAdSDK
//
//  Created by qusy on 2023/12/28.
//

#import <UIKit/UIKit.h>
#import <AdSetQDLAdSDK/AdSetQDLAdMeta.h>

typedef NS_ENUM(NSUInteger, AdSetQDLSplashAdCloseType) {
    AdSetQDLSplashAdCloseTypeNormal = 0,
};

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDLSplashAdDelegate;

@interface AdSetQDLSplashAd : NSObject

@property (nonatomic, weak) id<AdSetQDLSplashAdDelegate> delegate;

/// 栏位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;

/// 使用 controller present 落地页，默认使用广告 VC
@property (nonatomic, weak) UIViewController *viewController;

/// 广告点击自动关闭
@property (nonatomic) BOOL adClickToCloseAutomatically;

/// 广告物料
@property (nonatomic, strong) AdSetQDLAdMeta * meta;

/// 服务端竞价返回参数（仅在服务端竞价时有效，需要在 loadAdData 之前设置）
@property (nonatomic, strong) NSString *adm;

/// 初始化
/// @param slotID  栏位id
- (instancetype)initWithSlot:(NSString *)slotID;

/// 加载开屏广告；同一实例不能与 preLoadAdData 混用。
- (void)loadAdData;

/// 加载开屏缓存广告；同一实例不能与 loadAdData 混用。
- (void)preLoadAdData;

/// 展示开屏广告，自定义底部logo
- (void)showSplashViewController:(UIViewController *)controller withBottomView:(UIView *)bottomView;

/// 展示开屏广告
- (void)showSplashViewController:(UIViewController *)controller;

/// 展示开屏广告，自定义底部logo
- (void)showSplashWindow:(UIWindow *)window withBottomView:(UIView *)bottomView;

/// 展示开屏广告
- (void)showSplashWindow:(UIWindow *)window;

/// 关闭开屏广告
- (void)closeSplashAdWithCompletion:(void (^ __nullable)(void))completion;

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

@protocol AdSetQDLSplashAdDelegate <NSObject>

@optional

/// 开屏广告加载成功
- (void)adSetQDL_splashAdLoadSuccess:(AdSetQDLSplashAd *)splashAd;

/// 开屏广告加载失败
- (void)adSetQDL_splashAdLoadFail:(AdSetQDLSplashAd *)splashAd error:(NSError *)error;

/// 开屏广告渲染成功
- (void)adSetQDL_splashAdRenderSuccess:(AdSetQDLSplashAd *)splashAd;

/// 开屏广告渲染失败
- (void)adSetQDL_splashAdRenderFail:(AdSetQDLSplashAd *)splashAd error:(NSError *)error;

/// 开屏广告曝光
- (void)adSetQDL_splashAdDidShow:(AdSetQDLSplashAd *)splashAd;

/// 开屏广告点击
- (void)adSetQDL_splashAdDidClick:(AdSetQDLSplashAd *)splashAd;

/// 开屏广告即将关闭
- (void)adSetQDL_splashAdWillClose:(AdSetQDLSplashAd *)splashAd closeType:(AdSetQDLSplashAdCloseType)type;

/// 开屏广告关闭
- (void)adSetQDL_splashAdDidClose:(AdSetQDLSplashAd *)splashAd closeType:(AdSetQDLSplashAdCloseType)type;

// 开屏广告倒计时结束
- (void)adSetQDL_splashCountdownIsOver:(AdSetQDLSplashAd *)splashAd;

// 开屏广告展示失败
- (void)adSetQDL_splashAdShowFail:(AdSetQDLSplashAd *)splashAd error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
