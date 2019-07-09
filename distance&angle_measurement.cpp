
// C++ program for the Haversine Formula
// C++ program for the 
// haversine formula 
#include <iostream> 
#include <cmath> 
using namespace std; 
  
static double getdistance(double lat1, double lon1, 
                        double lat2, double lon2) 
    { 
        // distance between latitudes 
        // and longitudes 
        double diffLat = (lat2 - lat1) * 
                      M_PI / 180.0; 
        double diffLon = (lon2 - lon1) *  
                      M_PI / 180.0; 
  
        // convert to radians 
        lat1 = (lat1) * M_PI / 180.0; 
        lat2 = (lat2) * M_PI / 180.0; 
  
        // apply formulae 
        double p = pow(sin(diffLat / 2), 2) +  
                   pow(sin(diffLon / 2), 2) *  
                   cos(lat1) * cos(lat2); 
        double radius = 6371; 
        double c = 2 * asin(sqrt(p)); 
        return radius * c; 
    } 

static double getangle(double lat1, double lon1, double lat2, double lon2){
        double diffLat = (lat2 - lat1) ; 
        double diffLon = (lon2 - lon1) ; 

        double y = Math.sin(diffLon)*Math.cos(lat2);
        double x = Math.cos(lat2)*Math.sin(diffLon)-Math.sin(lat1)*Math.cos(lat2)*Math.cos(diffLon);
        double angle = Math.atan2(y,x);
        angle = Math.toDegree(angle);

        return angle
        
}    

  
// Driver code 
int main() 
{ 
    double lat1 =24.843027; 
    double lon1 =93.939140; 
    double lat2 = 24.246813; 
    double lon2 = 94.307838; 
      
    cout << getdistance(lat1, lon1, 
                      lat2, lon2) << " K.M."; 

    cout << getangle(lat1, lat2, lon1, lon2)<<"degree";                  
    return 0; 
} 