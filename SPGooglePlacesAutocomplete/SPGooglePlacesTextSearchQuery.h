//
//  SPGooglePlacesTextSearchQuery.h
//  Pods
//
//  Created by Sander van Dijk on 08/05/2014.
//
//

#import <CoreLocation/CoreLocation.h>

#import "SPGooglePlacesAutocompleteUtilities.h"

@interface SPGooglePlacesTextSearchQuery : NSObject {
    NSURLConnection *googleConnection;
    NSMutableData *responseData;
}

@property (nonatomic, copy, readonly) SPGooglePlacesTextSearchResultBlock resultBlock;

/*
 * Designated initializer
 * Must initialize an instance with a valid Google API key
 */
- (id)initWithApiKey:(NSString *)apiKey;

/*!
 Issues a Place Details request and pulls down the results. If called twice, the first request will be cancelled and the request will be re-issued using the current property values.
 */
- (void)fetchPlaces:(SPGooglePlacesTextSearchResultBlock)block;

#pragma mark -
#pragma mark Required parameters

/*!
 The text string on which to search, for example: "restaurant". The Place service will return candidate matches based on this string and order the results based on their perceived relevance.
 */
@property (nonatomic, strong) NSString* query;

/*!
 Indicates whether or not the Place request came from a device using a location sensor (e.g. a GPS) to determine the location sent in this request. This value must be either true or false. Defaults to YES.
 */
@property (nonatomic) BOOL sensor;

/*!
 Your application's API key. This key identifies your application for purposes of quota management. Visit the APIs Console to select an API Project and obtain your key. Maps API for Business customers must use the API project created for them as part of their Places for Business purchase. Defaults to kGoogleAPIKey.
 */
@property (nonatomic, strong) NSString *key;

#pragma mark -
#pragma mark Optional parameters

/*!
 The latitude/longitude around which to retrieve Place information. This must be specified as latitude,longitude. If you specify a location parameter, you must also specify a radius parameter.
 */
@property (nonatomic) CLLocationCoordinate2D location;

/*!
 Defines the distance (in meters) within which to bias Place results. The maximum allowed radius is 50 000 meters. Results inside of this region will be ranked higher than results outside of the search circle; however, prominent results from outside of the search radius may be included.
 */
@property (nonatomic) CGFloat radius;

/*!
 The language in which to return results. See the supported list of domain languages. Note that we often update supported languages so this list may not be exhaustive. If language is not supplied, the Place service will attempt to use the native language of the domain from which the request is sent.
 */
@property (nonatomic, strong) NSString *language;

@end
