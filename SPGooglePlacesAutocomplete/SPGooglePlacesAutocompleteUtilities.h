//
//  SPGooglePlacesAutocompleteUtilities.h
//  SPGooglePlacesAutocomplete
//
//  Created by Stephen Poletto on 7/18/12.
//  Modified by Shahar Hadas on 3/26/2014
//  Copyright (c) 2012 Stephen Poletto. All rights reserved.
//  Copyright (c) 2014 Sparq. All rights reserved.
//

#define kGoogleAPINSErrorCode 42

@class CLPlacemark;
@class CLLocation;

typedef NS_ENUM(NSInteger, SPGooglePlacesAutocompletePlaceType) {
    SPPlaceTypeAll,
    SPPlaceTypeGeocode,
    SPPlaceTypeEstablishment,
    SPPlaceTypeRegions,
    SPPlaceTypeCities
};



typedef void (^SPGooglePlacesPlacemarkResultBlock)(CLPlacemark *placemark, NSString *addressString, NSError *error);
typedef void (^SPGooglePlacesAutocompleteResultBlock)(NSArray *places, NSError *error);
typedef void (^SPGooglePlacesPlaceDetailResultBlock)(NSDictionary *placeDictionary, NSError *error);
typedef void (^SPGooglePlacesLocationResultBlock)(CLLocation *location, NSError *error);
typedef void (^SPGooglePlacesTextSearchResultBlock)(NSArray *places, NSError *error);

extern SPGooglePlacesAutocompletePlaceType SPPlaceTypeFromDictionary(NSDictionary *placeDictionary);
extern NSString *SPBooleanStringForBool(BOOL boolean);
extern NSString *SPPlaceTypeStringForPlaceType(SPGooglePlacesAutocompletePlaceType type);
extern BOOL SPIsEmptyString(NSString *string);

@interface NSArray(SPFoundationAdditions)
- (id)onlyObject;
@end