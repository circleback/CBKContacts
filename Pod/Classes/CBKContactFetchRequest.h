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

#import "CBKContact.h"

NS_ASSUME_NONNULL_BEGIN

@interface CBKContactFetchRequest : NSObject

/*!
 *  @abstract Use this initiliazer, using init raises an exception. Pass in the properties to fetch for the returned contacts.
 *
 *  @discussion Should only fetch the properties that will be used.
 */
- (instancetype)initWithKeysToFetch:(NSArray <id<CBKKeyDescriptor>>*)keysToFetch NS_DESIGNATED_INITIALIZER;

/*!
 * @abstract The predicate to match contacts against.
 *
 * @discussion Use only predicates from CNContact+Predicates.h. Compound predicates are not supported. Set to nil to match all contacts.
 */
@property (copy, nullable, NS_NONATOMIC_IOSONLY) NSPredicate *predicate;

/*!
 * @abstract The properties to fetch in the returned contacts.
 *
 * @discussion Should only fetch the properties that will be used. Can combine contact keys and contact key descriptors.
 */
@property (copy, NS_NONATOMIC_IOSONLY) NSArray<id<CBKKeyDescriptor>> *keysToFetch;

/*!
 * @abstract To return mutable contacts.
 *
 * @discussion If YES returns CNMutableContact objects, otherwise returns CNContact objects. Default is NO.
 */
@property (NS_NONATOMIC_IOSONLY) BOOL mutableObjects;

/*!
 * @abstract To return linked contacts as unified contacts.
 *
 * @discussion If YES returns unified contacts, otherwise returns individual contacts. Default is YES.
 *
 * @note A unified contact is the aggregation of properties from a set of linked individual contacts. If an individual contact is not linked then the unified contact is simply that individual contact.
 */
@property (NS_NONATOMIC_IOSONLY) BOOL unifyResults;

/*!
 * @abstract To return contacts in a specific sort order.
 *
 * @discussion Default is CNContactSortOrderNone.
 */
@property (NS_NONATOMIC_IOSONLY) CBKContactSortOrder sortOrder;



@end

NS_ASSUME_NONNULL_END
