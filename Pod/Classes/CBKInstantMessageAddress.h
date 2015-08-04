//  The MIT License (MIT)
//
//  Copyright (c) 2015 CircleBack, Inc.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CBKInstantMessageAddress : NSObject <NSCopying, NSSecureCoding>

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *username;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *service;

- (instancetype)initWithUsername:(NSString *)username service:(NSString *)service;

/*! Returns a user displayable property name. */
+ (NSString *)localizedStringForKey:(NSString *)key;

/*! Returns a user displayable service name. */
+ (NSString *)localizedStringForService:(NSString *)service;

@end


// Properties that are always fetched. Can be used with key value coding and observing.
FOUNDATION_EXPORT NSString * const CNInstantMessageAddressUsernameKey;
FOUNDATION_EXPORT NSString * const CNInstantMessageAddressServiceKey;

// Instant message services.
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceAIM;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceFacebook;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceGaduGadu;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceGoogleTalk;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceICQ;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceJabber;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceMSN;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceQQ;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceSkype;
FOUNDATION_EXPORT NSString * const CNInstantMessageServiceYahoo;

NS_ASSUME_NONNULL_END