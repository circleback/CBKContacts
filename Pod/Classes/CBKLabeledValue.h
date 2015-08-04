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

@interface CBKLabeledValue<ValueType : id <NSCopying, NSSecureCoding>> : NSObject <NSCopying, NSSecureCoding>

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *identifier;

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *label;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) ValueType value;

/*! Returns a new CNLabeledValue with a new identifier. */
+ (instancetype)labeledValueWithLabel:(nullable NSString *)label value:(ValueType)value;

/*! Initializes the CNLabeledValue with a new identifier. */
- (instancetype)initWithLabel:(nullable NSString *)label value:(ValueType)value;

/*! Returns a new CNLabeledValue with the existing value and identifier. */
- (instancetype)labeledValueBySettingLabel:(nullable NSString *)label;

/*! Returns a new CNLabeledValue with the existing label and identifier. */
- (instancetype)labeledValueBySettingValue:(ValueType)value;

/*! Returns a new CNLabeledValue with the existing identifier. */
- (instancetype)labeledValueBySettingLabel:(nullable NSString *)label value:(ValueType)value;

+ (NSString *)localizedStringForLabel:(NSString *)label;

@end


// Generic labels
FOUNDATION_EXPORT NSString * const CBKLabelHome                             NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSString * const CBKLabelWork                             NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSString * const CBKLabelOther                            NS_AVAILABLE(10_11, 9_0);

// Additional email labels
FOUNDATION_EXPORT NSString * const CBKLabelEmailiCloud                      NS_AVAILABLE(10_11, 9_0);

// URL address labels
FOUNDATION_EXPORT NSString * const CBKLabelURLAddressHomePage               NS_AVAILABLE(10_11, 9_0);

// Date labels
FOUNDATION_EXPORT NSString * const CBKLabelDateAnniversary                  NS_AVAILABLE(10_11, 9_0);

NS_ASSUME_NONNULL_END

