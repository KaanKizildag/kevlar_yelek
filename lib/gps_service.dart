import 'package:geolocator/geolocator.dart';

class GpsService {
  //Geolocator _geolocator = Geolocator();
  Position _position;

  Future<Position> getPosition() async {
    return await Geolocator.getCurrentPosition(
        desiredAccuracy: LocationAccuracy.high);
    //return _position;
  }
}
