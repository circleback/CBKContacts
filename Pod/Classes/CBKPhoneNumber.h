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


/*!
 * @abstract An immutable value object representing a phone number.
 *
 * @discussion CNPhoneNumber is thread safe.
 */
@interface CBKPhoneNumber : NSObject <NSCopying, NSSecureCoding>

/*! These will return nil if the stringValue is nil. */
+ (instancetype)phoneNumberWithStringValue:(NSString *)stringValue;
- (instancetype)initWithStringValue:(NSString *)string;

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *stringValue;

@end


// Phone number labels
FOUNDATION_EXPORT NSString * const CBKLabelPhoneNumberiPhone;
FOUNDATION_EXPORT NSString * const CBKLabelPhoneNumberMobile;
FOUNDATION_EXPORT NSString * const CBKLabelPhoneNumberMain;
FOUNDATION_EXPORT NSString * const CBKLabelPhoneNumberHomeFax;
FOUNDATION_EXPORT NSString * const CBKLabelPhoneNumberWorkFax;
FOUNDATION_EXPORT NSString * const CBKLabelPhoneNumberOtherFax;
FOUNDATION_EXPORT NSString * const CBKLabelPhoneNumberPager;

NS_ASSUME_NONNULL_END

