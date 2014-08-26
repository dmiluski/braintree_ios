#import <Foundation/Foundation.h>
#import "BTPaymentMethod.h"

extern NSString *const BTVenmoAppSwitchReturnURLErrorDomain;

typedef NS_ENUM(NSUInteger, BTVenmoAppSwitchReturnURLState) {
    BTVenmoAppSwitchReturnURLStateSucceeded,
    BTVenmoAppSwitchReturnURLStateFailed,
    BTVenmoAppSwitchReturnURLStateCanceled,
    BTVenmoAppSwitchReturnURLStateUnknown
};

/// This class interprets URLs received from the Venmo app via app switch returns.
///
/// Venmo Touch app switch authorization requests should result in success, failure or
/// user-initiated cancelation. These states are communicated in the url.
@interface BTVenmoAppSwitchReturnURL : NSObject

/// Evaluates whether the sourceApplication is allowed for Venmo Touch.
///
/// @param sourceApplication the source application that returned to this app via app switch (must be argument received in -[AppDelegate application:openURL:sourceApplication:annotation:])
///
/// @return YES if the sourceApplication is allowed for Venmo Touch
+ (BOOL)isValidSourceApplication:(NSString *)sourceApplication;

/// Initializes a new BTVenmoAppSwitchReturnURL
///
/// @param url an incoming app switch url
///
/// @return An initialized app switch return url
- (instancetype)initWithURL:(NSURL *)url;

/// The overall status of the app switch - success, failure or cancelation
@property (nonatomic, assign, readonly) BTVenmoAppSwitchReturnURLState state;

/// Creates and returns a payment method object that represents the payment method
/// authorized in the Venmo app switch.
///
///  @return A new payment method object with a transactable or vaultable nonce
@property (nonatomic, strong, readonly) BTPaymentMethod *paymentMethod;

/// If the return URL's state is BTVenmoAppSwitchReturnURLStateFailed,
/// the error returned from Venmo via the app switch.
@property (nonatomic, strong, readonly) NSError *error;

@end
