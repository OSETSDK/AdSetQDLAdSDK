//
//  AdSetQDLFeedAd.h
//  AdSetQDLAdSDK
//
//  Created by qusy on 2024/1/16.
//

#import <UIKit/UIKit.h>

#import <AdSetQDLAdSDK/AdSetQDLAdMeta.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDLFeedAdDelegate;

@interface AdSetQDLFeedAd : NSObject

@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
@property (nonatomic, strong, readonly, nullable) UIView *feedView;
/// 自定义尺寸
@property (nonatomic, assign) CGSize customSize;

@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, strong, readonly, nullable) AdSetQDLAdMeta *meta;

@property (nonatomic, weak) id<AdSetQDLFeedAdDelegate> delegate;

/// 服务端竞价返回参数（仅在服务端竞价时有效，需要在 loadAdData 之前设置）
@property (nonatomic, strong) NSString *adm;

/// 初始化
/// @param slotID  栏位id
- (instancetype)initWithSlot:(NSString *)slotID;

/// 加载广告
- (void)loadAdData;

/// 获取广告高度
- (CGFloat)handleFeedAdHeight;

/// 竞价成功
/// - Parameter auctionSecondPrice: 竞价第二名价格，单位是分
- (void)winNotice:(NSInteger)auctionSecondPrice;

/**
 竞价失败
 @param auctionPrice 胜出者价格，单位分
 @param winBidder 胜出者对应媒体
        如果需要扩展，可以直接传入自定义字符串
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

@protocol AdSetQDLFeedAdDelegate <NSObject>

@optional

/// 信息流广告加载成功
- (void)adSetQDL_feedAdLoadSuccess:(AdSetQDLFeedAd *)feedAd;

/// 信息流广告加载失败
- (void)adSetQDL_feedAdLoadFail:(AdSetQDLFeedAd *)feedAd error:(NSError *)error;

/// 信息流广告曝光
- (void)adSetQDL_feedAdDidShow:(AdSetQDLFeedAd *)feedAd;

/// 信息流广告点击
- (void)adSetQDL_feedAdDidClick:(AdSetQDLFeedAd *)feedAd;

/// 信息流广告关闭
- (void)adSetQDL_feedAdDidClose:(AdSetQDLFeedAd *)feedAd;

/// 落地页关闭
- (void)adSetQDL_feedAdDidCloseOtherController:(AdSetQDLFeedAd *)feedAd;

/// 信息流视频播放开始
- (void)adSetQDL_feedAdDidStart:(AdSetQDLFeedAd *)feedAd;

/// 信息流视频播放暂停
- (void)adSetQDL_feedAdDidPause:(AdSetQDLFeedAd *)feedAd;

/// 信息流视频播放继续
- (void)adSetQDL_feedAdDidResume:(AdSetQDLFeedAd *)feedAd;

/// 信息流视频播放完成
- (void)adSetQDL_feedAdVideoDidPlayComplection:(AdSetQDLFeedAd *)feedAd;

/// 信息流视频播放异常
- (void)adSetQDL_feedAdVideoDidPlayFinished:(AdSetQDLFeedAd *)feedAd didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
