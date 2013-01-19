# NSObject+DictionaryPropertyMapping

This is a category of NSObject to provide methods to inject a given NSDictionary based data source, e.g. coming from a JSON dictionary, into the object or to get the NSDictionary data source that is representing the current set of properties of an object.

The set of properties to inject/to read are not determined automatically, but have to be specified using a dictionary or an array.

## Usage:
### (1.1) Injecting using dictionary mapping
	// assuming myObject has properties NSString *firstName, *lastName;
	NSDictionary *data = @{@"first-name":@"John",@"last-name":@"Appleseed"};
	NSDictionary *mapping = @{@"first-name":@"firstName", @last-name":@"lastName"};
	[myObject inject:data usingMapping:mapping];

### (1.2) Injecting using array-mapping, if keys in data source match the properties
	// assuming myObject has properties NSString *firstName, *lastName;
	NSDictionary *data = @{@"firstName":@"John",@"lastName":@"Appleseed"};
	NSArray *list = @[@"firstName", @"lastName"];
	[myObject inject:data usingList:list];

### (2.1) Reading properties from object
	// assuming myObject has properties NSString *firstName, *lastName;
	NSDictionary *mapping = @{@"first-name":@"firstName", @last-name":@"lastName"};
	NSDictionary *representation = [myObject dictionaryRepresentationUsingMapping:mapping];

### (2.2) Reading properties from object using a list
	// assuming myObject has properties NSString *firstName, *lastName;
	NSArray *list = @[@"firstName", @"lastName"];
	NSDictionary *representation = [myObject dictionaryRepresentationUsingList:list];

## License
Under BSD License. I mean it's just a category!