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

@import AddressBook;
#import "CBKContactStore.h"

@interface CBKContactStore()

@property (NS_NONATOMIC_IOSONLY) ABAddressBookRef addressBook;

@end

@implementation CBKContactStore

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        self.addressBook = ABAddressBookCreate();
    }
    
    return self;
}

- (void)dealloc
{
    if (self.addressBook != NULL)
    {
        CFRelease(self.addressBook);
    }
}

+ (CBKAuthorizationStatus)authorizationStatusForEntityType:(CBKEntityType)entityType
{
    ABAuthorizationStatus status = ABAddressBookGetAuthorizationStatus();
    return (CBKAuthorizationStatus) status;
}

- (void)requestAccessForEntityType:(CBKEntityType)entityType completionHandler:(void (^)(BOOL granted, NSError *__nullable error))completionHandler;
{
    ABAddressBookRef abRef = ABAddressBookCreate();
    ABAddressBookRequestAccessWithCompletion(abRef, ^(bool ab_granted, CFErrorRef ab_error) {
        
        BOOL _granted = ab_granted;
        NSError *_error = (__bridge_transfer NSError *)ab_error;
        
        completionHandler(_granted, _error);
        
        if (_granted)
        {
            self.addressBook = abRef;
        }
        else
        {
            CFRelease(abRef);
        }
    });
}

@end
