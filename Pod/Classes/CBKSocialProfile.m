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

#import "CBKSocialProfile.h"

@interface CBKSocialProfile()
@property (readwrite, copy, NS_NONATOMIC_IOSONLY) NSString *urlString;
@property (readwrite, copy, NS_NONATOMIC_IOSONLY) NSString *username;
@property (readwrite, copy, NS_NONATOMIC_IOSONLY) NSString *userIdentifier;
@property (readwrite, copy, NS_NONATOMIC_IOSONLY) NSString *service;
@end

@implementation CBKSocialProfile

- (instancetype)initWithUrlString:(nullable NSString *)urlString username:(nullable NSString *)username userIdentifier:(nullable NSString *)userIdentifier service:(nullable NSString *)service
{
    self = [super init];
    
    self.urlString = urlString;
    self.username = username;
    self.userIdentifier = userIdentifier;
    self.service = service;
    
    return self;
}

- (NSString *)debugDescription
{
    return [self description];
}

#pragma mark - NSCoding

- (instancetype)initWithCoder:(nonnull NSCoder *)aDecoder
{
    return [super init];
}

- (void)encodeWithCoder:(nonnull NSCoder *)aCoder
{
    
}

+ (BOOL)supportsSecureCoding
{
    return YES;
}

#pragma mark - NSCopying
- (instancetype)copyWithZone:(nullable NSZone *)zone
{
    return [[self.class alloc] init];
}

#pragma mark - 
/*! Returns a user displayable property name. */
+ (NSString *)localizedStringForKey:(NSString *)key
{
    return @"";
}

/*! Returns a user displayable service name. */
+ (NSString* )localizedStringForService:(NSString *)service
{
    return @"";
}


@end
