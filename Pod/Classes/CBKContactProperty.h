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

@class CBKContact;

@interface CBKContactProperty : NSObject <NSCopying, NSSecureCoding>

@property (readonly, copy, NS_NONATOMIC_IOSONLY) CBKContact *contact;

/*!
 * @abstract The key of the contact property, as defined in CNContact.h.
 */
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *key;

/*!
 * @abstract The value of the property.
 */
@property (readonly, nullable, NS_NONATOMIC_IOSONLY) id value;

/*!
 * @abstract The identifier of the labeled value if the property is an array of labeled values, otherwise is nil.
 */
@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *identifier;

/*!
 * @abstract The label of the labeled value if the property is an array of labeled values, otherwise is nil.
 */
@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *label;

@end

NS_ASSUME_NONNULL_END

