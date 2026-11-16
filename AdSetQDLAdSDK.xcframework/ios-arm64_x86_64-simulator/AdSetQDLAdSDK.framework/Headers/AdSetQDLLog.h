//
//  AdSetQDLLog.h
//  AdSetQDLAdSDK
//
//  Created by qusy on 2023/12/28.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(int, AdSetQDLLoggingLevel) {
    kAdSetQDLLoggingLevel_Info,
    kAdSetQDLLoggingLevel_Warning,
    kAdSetQDLLoggingLevel_Error,
    kAdSetQDLLoggingLevel_Log,
};

FOUNDATION_EXPORT void AdSetQDLLogMsg(AdSetQDLLoggingLevel level, NSString *format, ...) NS_FORMAT_FUNCTION(2, 3) NS_NO_TAIL_CALL;

#define AdSetQDLLog(fmt, ...)         AdSetQDLLogMsg(kAdSetQDLLoggingLevel_Info, @"%s: " fmt, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#define AdSetQDLLogWarning(fmt, ...)  AdSetQDLLogMsg(kAdSetQDLLoggingLevel_Warning, @"%s: " fmt, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#define AdSetQDLLogError(fmt, ...)    AdSetQDLLogMsg(kAdSetQDLLoggingLevel_Error, @"%s: " fmt, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#define AdSetQDLLogPublic(fmt, ...)   AdSetQDLLogMsg(kAdSetQDLLoggingLevel_Log, @"%s: " fmt, __PRETTY_FUNCTION__, ##__VA_ARGS__)

@interface AdSetQDL_Log : NSObject
+ (void)info:(AdSetQDLLoggingLevel)level format:(NSString *)format;
@end
