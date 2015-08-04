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

@class CBKContact, CBKMutableContact, CBKGroup, CBKMutableGroup;

/*!
 * @abstract Specifies the changes to save.
 *
 * @discussion Create a new save request for each save execution on the contact store. Can have many changes batched into one save request. Do not access objects in the save request when it is executing.  A save request only applies the changes to the objects. If there are overlapping changes with multiple, concurrent CNSaveRequests then the last saved change wins.
 *
 * If adding an object (contact, group, container) and it is already in the contact store then the executing save request will fail to add that object and will return the error CNErrorCodeInsertedRecordAlreadyExists with CNErrorUserInfoAffectedRecordsKey value as an array containing that object.
 *
 * If updating/deleting an object (contact, group, container) and it is not in the contact store then the executing save request will fail to update/delete that object and will return the error CNErrorCodeRecordDoesNotExist with CNErrorUserInfoAffectedRecordsKey value as an array containing that object.
 *
 */

@interface CBKSaveRequest : NSObject

/*!
 * @abstract Add a new contact to the contact store.
 *
 * @discussion The contact may be modified by the executing save request. If the contact was previously specified to be deleted in the save request that will no longer occur.
 *
 * @param contact The new contact to add.
 * @param identifier The container identifier to add the new contact to. Set to nil for the default container.
 */
- (void)addContact:(CBKMutableContact *)contact toContainerWithIdentifier:(nullable NSString *)identifier;

/*!
 * @abstract Update an existing contact in the contact store.
 *
 * @discussion The contact must already exist in the contact store. The contact may be modified by the executing save request.
 */
- (void)updateContact:(CBKMutableContact *)contact;

/*!
 * @abstract Delete a contact from the contact store.
 *
 * @discussion If the contact was previously specified to be added in the save request that will no longer occur.
 */
- (void)deleteContact:(CBKMutableContact *)contact;

/*!
 * @abstract Add a new group to the contact store.
 *
 * @discussion If the group was previously specified to be deleted in the save request that will no longer occur.
 *
 * @param group The new group to add.
 * @param identifier The container identifier to add the new group to. Set to nil for the default container.
 */
- (void)addGroup:(CBKMutableGroup *)group toContainerWithIdentifier:(nullable NSString *)identifier;

/*!
 * @abstract Update an existing group in the contact store.
 *
 * @discussion The group must already exist in the contact store.
 */
- (void)updateGroup:(CBKMutableGroup *)group;

/*!
 * @abstract Delete a group from the contact store.
 *
 * @discussion The contacts in the group are not deleted. If the group was previously specified to be added in the save request that will no longer occur.
 */
- (void)deleteGroup:(CBKMutableGroup *)group;

// TODO: determine these availabilites against address book
/*!
 * @abstract Add a new subgroup to a group.
 *
 * @discussion If the subgroup was previously specified to be deleted in the save request that will no longer occur.
 *
 * @param subgroup The new group to add.
 * @param group The group to add the subgroup to.
 */
- (void)addSubgroup:(CBKGroup *)subgroup toGroup:(CBKGroup *)group NS_AVAILABLE(10_11, NA);

/*!
 * @abstract Remove a subgroup from a group.
 *
 * @discussion The contacts in the subgroup's membership are not affected. If the subgroup was previously specified to be added in the save request that will no longer occur.
 *
 * @param subgroup The new group to add.
 * @param group The group to add the subgroup to.
 */
- (void)removeSubgroup:(CBKGroup *)subgroup fromGroup:(CBKGroup *)group NS_AVAILABLE(10_11, NA);

/*!
 * @abstract Add a new member to a group.
 *
 * @discussion If the membership was previously specified to be deleted in the save request that will no longer occur.
 *
 * @param contact The new member to add to the group.
 * @param group The group to add the member to.
 */
- (void)addMember:(CBKContact *)contact toGroup:(CBKGroup *)group;

/*!
 * @abstract Remove a member from a group.
 *
 * @discussion The contact is not deleted. It is only removed as a member of the group. If the membership was previously specified to be added in the save request that will no longer occur.
 *
 * @param contact The member to remove from the group.
 * @param group The group to remove the member from.
 */
- (void)removeMember:(CBKContact *)contact fromGroup:(CBKGroup *)group;

@end

NS_ASSUME_NONNULL_END
