#ifndef MAP_H
#define MAP_H

#include <map>
#include <string>
#include <iostream>

class Map {
	private:
		std::map<std::string, std::map<std::string, std::string>> locations; // Navigation map
		std::map<std::string, std::string> descriptions; // Descriptions for each location
		std::map<std::string, std::string> narratives; // Narratives for each location
		std::string currentLocation;

	public:
		Map();
		void addLocation(const std::string& locationName, const std::map<std::string, std::string>& directions, const std::string& description, const std::string& narrative = "");
		bool move(const std::string& direction);
		std::string getCurrentLocationDescription() const;
		std::string getCurrentNarrative() const;
		std::string describeCurrentLocation() const;
		void setCurrentLocation(const std::string& location);
		std::string getCurrentLocation() const; // Get current location
};


#endif

