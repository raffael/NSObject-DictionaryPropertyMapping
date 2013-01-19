//
//  NSObject+DictionaryPropertyMapping.h
//
//  Created by Raffael Hannemann on 04.01.13.
//  Copyright (c) 2013 raffael.me. All rights reserved.
//

// Under BSD License.

/**
 * This is a category of NSObject to provide methods to inject a given
 * NSDictionary based data source, e.g. coming from a JSON dictionary,
 * into the object or to get the NSDictionary data source that is representing
 * the current set of properties of an object.
 *
 * The set of properties to inject/to read are not determined automatically,
 * but have to be specified using a dictionary or an array.
 *
 * Usage:
 * (1.1) Injecting using dictionary mapping
 * // assuming myObject has properties NSString *firstName, *lastName;
 * NSDictionary *data = @{@"first-name":@"John",@"last-name":@"Appleseed"};
 * NSDictionary *mapping = @{@"first-name":@"firstName", @last-name":@"lastName"};
 * [myObject inject:data usingMapping:mapping];
 *
 * (1.2) Injecting using array-mapping, if keys in data source match the properties
 * // assuming myObject has properties NSString *firstName, *lastName;
 * NSDictionary *data = @{@"firstName":@"John",@"lastName":@"Appleseed"};
 * NSArray *list = @[@"firstName", @"lastName"];
 * [myObject inject:data usingList:list];
 *
 * (2.1) Reading properties from object
 * // assuming myObject has properties NSString *firstName, *lastName;
 * NSDictionary *mapping = @{@"first-name":@"firstName", @last-name":@"lastName"};
 * NSDictionary *representation = [myObject dictionaryRepresentationUsingMapping:mapping];
 *
 * (2.2) Reading properties from object using a list
 * // assuming myObject has properties NSString *firstName, *lastName;
 * NSArray *list = @[@"firstName", @"lastName"];
 * NSDictionary *representation = [myObject dictionaryRepresentationUsingList:list];
 */

#import <Foundation/Foundation.h>

@interface NSObject (DictionaryPropertyMapping)

/** Inject a given dictionary data source into the object using a key-value mapping.

 @param dataSource The data source to inject into the object.
 @param mapping The key-value mapping acting as a router while injecting.
 */
- (BOOL) inject: (NSDictionary *) dataSource usingMapping: (NSDictionary *) mapping;

/** Get a dictionary data source representing the object using a key-value mapping.

 @param mapping The key-value mapping containing the property names to read.
 */
- (NSDictionary *) dictionaryRepresentationUsingMapping: (NSDictionary *) mapping;

/** Inject a given dictionary data source into the object using a list of property names, which is useful if the object and the data source share the same property definition.

 @param dataSource The data source to inject into the object.
 @param list The array containing the property names to inject.
 */
- (BOOL) inject: (NSDictionary *) dataSource usingList: (NSArray *) list;

/** Get a dictionary data source representing the object using a list of property names, which is useful if the object and the data source share the same property definition.

 @param list The array containing the property names to read.
 */
- (NSDictionary *) dictionaryRepresentationUsingList: (NSArray *) list;

@end
