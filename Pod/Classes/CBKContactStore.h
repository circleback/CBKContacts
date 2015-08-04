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

@class CBKGroup, CBKContainer, CBKContactFetchRequest,CBKSaveRequest;
/*!
 * @abstract The entities the user can grant access to.
 */
typedef NS_ENUM(NSInteger, CBKEntityType)
{
    /*! The user's contacts. */
    CBKEntityTypeContacts
};

/*!
 * @abstract The authorization the user has given the application to access an entity type.
 */
typedef NS_ENUM(NSInteger, CBKAuthorizationStatus)
{
    /*! The user has not yet made a choice regarding whether the application may access contact data. */
    CBKAuthorizationStatusNotDetermined = 0,
    /*! The application is not authorized to access contact data.
     *  The user cannot change this application’s status, possibly due to active restrictions such as parental controls being in place. */
    CBKAuthorizationStatusRestricted,
    /*! The user explicitly denied access to contact data for the application. */
    CBKAuthorizationStatusDenied,
    /*! The application is authorized to access contact data. */
    CBKAuthorizationStatusAuthorized
};

@interface CBKContactStore : NSObject

#pragma mark - Privacy Access

/*!
 * @abstract Indicates the current authorization status to access contact data.
 *
 * @discussion Based upon the access, the application could display or hide its UI elements that would access any Contacts API. This method is thread safe.
 *
 * @return Returns the authorization status for the given entityType.
 */
+ (CBKAuthorizationStatus)authorizationStatusForEntityType:(CBKEntityType)entityType;

/*!
 * @abstract Request access to the user's contacts.
 *
 * @discussion Users are able to grant or deny access to contact data on a per-application basis. To request access to contact data, call requestAccessForEntityType:completionHandler:. This will not block the application while the user is being asked to grant or deny access. The user will only be prompted the first time access is requested; any subsequent CNContactStore calls will use the existing permissions. The completion handler is called on an arbitrary queue.
 *
 * @note Recommended to use CNContactStore instance methods in this completion handler instead of the UI main thread. This method is optional when CNContactStore is used on a background thread. If it is not used in that case, CNContactStore will block if the user is asked to grant or deny access.
 *
 * @param entityType Set to CNEntityTypeContacts.
 * @param completionHandler This block is called upon completion. If the user grants access then granted is YES and error is nil. Otherwise granted is NO with an error.
 */
- (void)requestAccessForEntityType:(CBKEntityType)entityType completionHandler:(void (^)(BOOL granted, NSError *__nullable error))completionHandler;

#pragma mark - Unified Contacts Helpers

/*!
 * @abstract Fetch all unified contacts matching a given predicate.
 *
 * @discussion Use only predicates from CNContact+Predicates.h. Compound predicates are not supported. Due to unification the returned contacts may have a different identifier.
 *
 * @note To fetch all contacts use enumerateContactsWithFetchRequest:error:usingBlock:.
 *
 * @param predicate The predicate to match against.
 * @param keys The properties to fetch into the returned CNContact objects. Should only fetch the properties that will be used. Can combine contact keys and contact key descriptors.
 * @param error If an error occurs, contains error information.
 * @return An array of CNContact objects matching the predicate. If no matches are found, an empty array is returned. If an error occurs, nil is returned.
 */
- (nullable NSArray<CBKContact*> *)unifiedContactsMatchingPredicate:(NSPredicate *)predicate keysToFetch:(NSArray<id<CBKKeyDescriptor>> *)keys error:(NSError *__nullable *__nullable)error;

/*!
 * @abstract Fetch a unified contact with a given identifier.
 *
 * @discussion Due to unification the returned contact may have a different identifier. To fetch a batch of contacts by identifiers use [CNContact predicateForContactsWithIdentifiers:].
 *
 * @param identifier The identifier of the contact to fetch.
 * @param keys The properties to fetch into the returned CNContact object. Should only fetch the properties that will be used. Can combine contact keys and contact key descriptors.
 * @param error If an error occurs, contains error information.
 * @return The unified contact matching or linked to the identifier. If no contact with the given identifier is found, nil is returned abd error is set to CNErrorCodeRecordDoesNotExist.
 */
- (nullable CBKContact *)unifiedContactWithIdentifier:(NSString *)identifier keysToFetch:(NSArray<id<CBKKeyDescriptor>> *)keys error:(NSError *__nullable *__nullable)error;

/*!
 * @abstract Fetch the unified contact that is the "me" card.
 *
 * @discussion Fetches the contact that is represented in the user interface as "My Card".
 *
 * @param keys The properties to fetch into the returned CNContact object. Should only fetch the properties that will be used. Can combine contact keys and contact key descriptors.
 * @param error If an error occurs, contains error information.
 * @return The unified contact that is the "me" card. If no "me" card is set, nil is returned.
 */
- (nullable CBKContact *)unifiedMeContactWithKeysToFetch:(NSArray<id<CBKKeyDescriptor>> *)keys error:(NSError *__nullable *__nullable)error NS_AVAILABLE(10_11, NA) __WATCHOS_PROHIBITED;


#pragma mark - Fetch and Save

/*!
 * @abstract Enumerates all contacts matching a contact fetch request.
 *
 * @discussion This method will wait until the enumeration is finished. If there are no results the block is not called and YES is returned.
 *
 * @param fetchRequest The contact fetch request that specifies the search criteria.
 * @param error If an error occurs, contains error information.
 * @param block Called for each matching contact. Set *stop to YES to stop the enumeration.
 * @return YES if successful, otherwise NO.
 */
- (BOOL)enumerateContactsWithFetchRequest:(CBKContactFetchRequest *)fetchRequest error:(NSError *__nullable *__nullable)error usingBlock:(void (^)(CBKContact *contact, BOOL *stop))block;

/*!
 * @abstract Fetch all groups matching a given predicate.
 *
 * @discussion Use only predicates from CNGroup+Predicates.h. Compound predicates are not supported.
 *
 * @param predicate The predicate to match against. Set to nil to match all groups.
 * @param error If an error occurs, contains error information.
 * @return An array of CNGroup objects matching the predicate. If no matches are found, an empty array is returned. If an error occurs, nil is returned.
 */
- (nullable NSArray<CBKGroup*> *)groupsMatchingPredicate:(nullable NSPredicate *)predicate error:(NSError *__nullable *__nullable)error;

/*!
 * @abstract Fetch all containers matching a given predicate.
 *
 * @discussion Use only predicates from CNContainer+Predicates.h. Compound predicates are not supported.
 *
 * @param predicate The predicate to match against. Set to nil to match all containers.
 * @param error If an error occurs, contains error information.
 * @return An array of CNContainer objects matching the predicate. If no matches are found, an empty array is returned. If an error occurs, nil is returned.
 */
- (nullable NSArray<CBKContainer*> *)containersMatchingPredicate:(nullable NSPredicate *)predicate error:(NSError *__nullable *__nullable)error;

/*!
 * @abstract Executes a save request.
 *
 * @discussion Do not access objects when save request is executing. A save request with contacts may modify the contacts while executing. A save request only applies the changes to the objects. If there are overlapping changes with multiple, concurrent CNSaveRequests then the last saved change wins.
 *
 * @param saveRequest Save request to execute.
 * @param error If an error occurs, contains error information.
 * @return YES if successful, otherwise NO.
 */
- (BOOL)executeSaveRequest:(CBKSaveRequest *)saveRequest error:(NSError *__nullable *__nullable)error __WATCHOS_PROHIBITED;


#pragma mark - Miscellaneous

/*!
 *  @abstract The identifier of the default container.
 *
 *  @discussion This identifier can be used to fetch the default container.
 *
 *  @return The identifier of the default container.
 */
- (NSString *)defaultContainerIdentifier;

@end

NS_ASSUME_NONNULL_END