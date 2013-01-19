//
//  NSObject+DictionaryPropertyMapping.m
//
//  Created by Raffael Hannemann on 04.01.13.
//  Copyright (c) 2013 raffael.me. All rights reserved.
//

#import "NSObject+DictionaryPropertyMapping.h"

@implementation NSObject (DictionaryPropertyMapping)

- (BOOL) inject:(NSDictionary *)dataSource usingMapping:(NSDictionary *)mapping {
	NSAssert(mapping,@"Dictionary mapping not set to inject data into object");
	if (mapping==nil || dataSource==nil)
		return NO;

	// cycle through the keys specified in the mapping
	for (NSString *property in [mapping allKeys]) {
		// get the key path from the mapping for the property
		NSString *keyPath = [mapping valueForKey:property];
		// get the value for the property from the data source
		NSString *newValue = [dataSource valueForKeyPath:property];
		// inject the value into the object
		if (newValue!=nil)
			[self setValue:newValue forKey:keyPath];
	}
	return YES;
}

- (BOOL) inject:(NSDictionary *)dataSource usingList:(NSArray *)list {
	NSMutableDictionary *mapping = [NSMutableDictionary dictionary];
	for (NSString *key in list)
		[mapping setObject:key forKey:key];
	return [self inject:dataSource usingMapping:mapping];
}

- (NSDictionary *) dictionaryRepresentationUsingMapping:(NSDictionary *)mapping {
	NSAssert(mapping, @"Mapping not set for suckUsingMapping:; operation.");

	NSMutableDictionary *tmpDict = [NSMutableDictionary dictionary];

	for (NSString *property in mapping) {
		NSString *keyPath = [mapping objectForKey:property];

		if ([self valueForKeyPath:keyPath])
			[tmpDict setObject:[self valueForKey:property] forKey:property];
	}
	return [NSDictionary dictionaryWithDictionary:tmpDict];
}

- (id) valueForUndefinedKey:(NSString *)key {
	NSLog(@"Warning: undefined object for key path '%@' for object of class '%@', returning empty string.",key,[[self class] description]);
	return @"";
}

- (NSDictionary *) dictionaryRepresentationUsingList:(NSArray *)list {
	NSMutableDictionary *mapping = [NSMutableDictionary dictionary];
	for (NSString *key in list)
		[mapping setObject:key forKey:key];
	return [self dictionaryRepresentationUsingMapping:mapping];
}
	 
@end
