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

#import "CBKLabeledValue.h"
#import "NSObject+CBKContacts.h"

@interface CBKLabeledValue()
@property (readwrite, copy, NS_NONATOMIC_IOSONLY) NSString *identifier;

@property (readwrite, copy, NS_NONATOMIC_IOSONLY) NSString *label;
@property (readwrite, copy, NS_NONATOMIC_IOSONLY) id<NSCopying,NSSecureCoding> value;
@end

@implementation CBKLabeledValue

+ (instancetype)labeledValueWithLabel:(nullable NSString *)label value:(nonnull id<NSCopying,NSSecureCoding>)value
{
    id labeledValue = [[self alloc] initWithLabel:label value:value];
    return labeledValue;
}

- (instancetype)initWithLabel:(nullable NSString *)label value:(nonnull id<NSCopying,NSSecureCoding>)value
{
    self = [super init];
    self.label = label;
    self.value = value;
    
    return self;
}

/*! Returns a new CNLabeledValue with the existing value and identifier. */
- (instancetype)labeledValueBySettingLabel:(nullable NSString *)label
{
    id value = [[self class] labeledValueWithLabel:label value:self.value];
    return value;
}

/*! Returns a new CNLabeledValue with the existing label and identifier. */
- (instancetype)labeledValueBySettingValue:(nonnull id<NSCopying,NSSecureCoding>)value
{
    id labeledValue = [[self class] labeledValueWithLabel:self.label value:value];
    return labeledValue;
}

/*! Returns a new CNLabeledValue with the existing identifier. */
- (instancetype)labeledValueBySettingLabel:(nullable NSString *)label value:(nonnull id<NSCopying,NSSecureCoding>)value
{
    return [[self class] labeledValueWithLabel:label value:value];
}

- (NSString *)description
{
    NSString *className = NSStringFromClass(self.class);
    NSDictionary *params = @{@"identifier"  : self.identifier,
                             @"label"       : self.label,
                             @"value"       : self.value};
    
    NSMutableArray *pairs = [NSMutableArray arrayWithCapacity:params.count];
    [params enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        NSString *component = [[key stringByAppendingString:@"="] stringByAppendingString:[obj description]];
        [pairs addObject: component];
    }];
    
    NSString *paramString = [pairs componentsJoinedByString:@", "];
    
    return [NSString stringWithFormat:@"<%@: %@: %@>", className, [self _cbk_addressString], paramString];
}

- (NSString *)debugDescription
{
    return [self description];
}

+ (NSString *)localizedStringForLabel:(NSString *)label
{
    return @"";
}

#pragma mark - NSCopying
- (instancetype)copyWithZone:(nullable NSZone *)zone
{
    return [[self.class alloc] init];
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


@end
