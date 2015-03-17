#import <Foundation/Foundation.h>

@interface BTTestClientTokenFactory : NSObject

+ (NSString *)tokenWithVersion:(NSInteger)version;
+ (NSString *)tokenWithVersion:(NSInteger)version
                     overrides:(NSDictionary *)dictionary;
+ (NSMutableDictionary *)configuration;
+ (NSMutableDictionary *)configurationWithOverrides:(NSDictionary *)dictionary;

@end