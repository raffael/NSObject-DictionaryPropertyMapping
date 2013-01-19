# NSObject+DictionaryPropertyMapping

This is a category of NSObject to provide methods to inject a given NSDictionary based data source, e.g. coming from a JSON dictionary, into the object or to get the NSDictionary data source that is representing the current set of properties of an object.

The set of properties to inject/to read are not determined automatically, but have to be specified using a dictionary or an array.

## Scenario

Say we have a JSON result coming from the server:

	{
		"first-name": "John",
		"last-name": "Appleseed"
	}

and we have a *Person* object with the two NSString properties *fastName* and *lastName*. Instead of cycling through the entries of our JSON NSDictionary, and manually setting the properties using the synthesized setter methods, let's just inject the NSDictionary by providing both the data and a mapping dictionary:

	[person inject:JSON usingMapping:@{
		@"first-name": @"firstName",
		@"last-name": @"lastName"
	}];

That's it.

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