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
#import "CBKLabeledValue.h"
#import "CBKPhoneNumber.h"
#import "CBKPostalAddress.h"
#import "CBKContactRelation.h"
#import "CBKSocialProfile.h"
#import "CBKInstantMessageAddress.h"


NS_ASSUME_NONNULL_BEGIN
/*!
 * @abstract Sort order for contacts.
 *
 * @discussion CNContactSortOrderUserDefault is the user's preferred sort order.
 */
typedef NS_ENUM(NSInteger, CBKContactSortOrder)
{
    CNContactSortOrderNone,
    CNContactSortOrderUserDefault,
    CNContactSortOrderGivenName,
    CNContactSortOrderFamilyName,
};

typedef NS_ENUM(NSInteger, CBKContactType)
{
    CNContactTypePerson,
    CNContactTypeOrganization,
};

@protocol CBKKeyDescriptor <NSObject, NSSecureCoding, NSCopying>
@end

@interface CBKContact : NSObject

/*! The identifier is unique among contacts on the device. It can be saved and used for fetching contacts next application launch. */
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *identifier;

@property (readonly, NS_NONATOMIC_IOSONLY) CBKContactType contactType;

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *namePrefix;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *givenName;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *middleName;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *familyName;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *previousFamilyName;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *nameSuffix;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *nickname;

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *phoneticGivenName;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *phoneticMiddleName;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *phoneticFamilyName;

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *organizationName;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *departmentName;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *jobTitle;

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSString *note;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSData *imageData;
@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSData *thumbnailImageData;
@property (readonly, NS_NONATOMIC_IOSONLY) BOOL imageDataAvailable NS_AVAILABLE(NA, 9_0);

@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSArray<CBKLabeledValue<CBKPhoneNumber*>*>             *phoneNumbers;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSArray<CBKLabeledValue<NSString*>*>                  *emailAddresses;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSArray<CBKLabeledValue<CBKPostalAddress*>*>           *postalAddresses;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSArray<CBKLabeledValue<NSString*>*>                  *urlAddresses;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSArray<CBKLabeledValue<CBKContactRelation*>*>         *contactRelations;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSArray<CBKLabeledValue<CBKSocialProfile*>*>           *socialProfiles;
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSArray<CBKLabeledValue<CBKInstantMessageAddress*>*>   *instantMessageAddresses;

/*! The Gregorian birthday. */
@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSDateComponents *birthday;

/*! The alternate birthday (Lunisolar). */
@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSDateComponents *nonGregorianBirthday;

/*! Other Gregorian dates (anniversaries, etc). */
@property (readonly, copy, NS_NONATOMIC_IOSONLY) NSArray<CBKLabeledValue<NSDateComponents*>*> *dates;


// Key Availability

/*! Returns YES if the value for the specified key was fetched. */
- (BOOL)isKeyAvailable:(NSString *)key;

/*! Returns YES if the values for the keys specified by all the descriptors were fetched. */
- (BOOL)areKeysAvailable:(NSArray <id<CBKKeyDescriptor>>*)keyDescriptors;


// Key Localization

/*! Returns a user displayable property name. */
+ (NSString *)localizedStringForKey:(NSString *)key;


// Contact Sort Comparator

/*! The contact comparator for a given sort order. */
+ (NSComparator)comparatorForNameSortOrder:(CBKContactSortOrder)sortOrder;

/*! Use to fetch all contact keys required for the contact sort comparator. */
+ (id<CBKKeyDescriptor>)descriptorForAllComparatorKeys;


// Unification
/*! Returns YES if the receiver was fetched as a unified contact and includes the contact having contactIdentifier in its unification */
- (BOOL)isUnifiedWithContactWithIdentifier:(NSString*)contactIdentifier;


@end

FOUNDATION_EXPORT NSString * const CNContactPropertyNotFetchedExceptionName;

// Properties that are always fetched. Can be used with key value coding and observing.
FOUNDATION_EXPORT NSString * const CNContactIdentifierKey;

// Optional properties that can be fetched. Can be used with key value coding and observing.
FOUNDATION_EXPORT NSString * const CNContactNamePrefixKey;
FOUNDATION_EXPORT NSString * const CNContactGivenNameKey;
FOUNDATION_EXPORT NSString * const CNContactMiddleNameKey;
FOUNDATION_EXPORT NSString * const CNContactFamilyNameKey;
FOUNDATION_EXPORT NSString * const CNContactPreviousFamilyNameKey;
FOUNDATION_EXPORT NSString * const CNContactNameSuffixKey;
FOUNDATION_EXPORT NSString * const CNContactNicknameKey;
FOUNDATION_EXPORT NSString * const CNContactPhoneticGivenNameKey;
FOUNDATION_EXPORT NSString * const CNContactPhoneticMiddleNameKey;
FOUNDATION_EXPORT NSString * const CNContactPhoneticFamilyNameKey;
FOUNDATION_EXPORT NSString * const CNContactOrganizationNameKey;
FOUNDATION_EXPORT NSString * const CNContactDepartmentNameKey;
FOUNDATION_EXPORT NSString * const CNContactJobTitleKey;
FOUNDATION_EXPORT NSString * const CNContactBirthdayKey;
FOUNDATION_EXPORT NSString * const CNContactNonGregorianBirthdayKey;
FOUNDATION_EXPORT NSString * const CNContactNoteKey;
FOUNDATION_EXPORT NSString * const CNContactImageDataKey;
FOUNDATION_EXPORT NSString * const CNContactThumbnailImageDataKey;
FOUNDATION_EXPORT NSString * const CNContactImageDataAvailableKey              NS_AVAILABLE(NA, 9_0);
FOUNDATION_EXPORT NSString * const CNContactTypeKey;
FOUNDATION_EXPORT NSString * const CNContactPhoneNumbersKey;
FOUNDATION_EXPORT NSString * const CNContactEmailAddressesKey;
FOUNDATION_EXPORT NSString * const CNContactPostalAddressesKey;
FOUNDATION_EXPORT NSString * const CNContactDatesKey;
FOUNDATION_EXPORT NSString * const CNContactUrlAddressesKey;
FOUNDATION_EXPORT NSString * const CNContactRelationsKey;
FOUNDATION_EXPORT NSString * const CNContactSocialProfilesKey;
FOUNDATION_EXPORT NSString * const CNContactInstantMessageAddressesKey;

NS_ASSUME_NONNULL_END
