def calculate_bearing(self, lat1, long1, lat2, long2):
    dLon = math.radians(long2 - long1)  # Convert longitude difference to radians
    lat1 = math.radians(lat1)  # Convert latitudes to radians
    lat2 = math.radians(lat2)

    y = math.sin(dLon) * math.cos(lat2)
    x = math.cos(lat1) * math.sin(lat2) - math.sin(lat1) * math.cos(lat2) * math.cos(dLon)

    brng = math.atan2(y, x)  # Compute the bearing in radians
    brng = math.degrees(brng)  # Convert the bearing to degrees
    brng = (brng + 360) % 360  # Ensure the bearing is in the range [0, 360)

    return brng