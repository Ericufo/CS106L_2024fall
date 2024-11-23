/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
#include <numeric>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  double min_temp = *std::min_element(dailyWeather.begin(), dailyWeather.end());
  double max_temp = *std::max_element(dailyWeather.begin(), dailyWeather.end());
  double avg_temp = std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0) / dailyWeather.size();
  Forecast daily_forecast = {min_temp, max_temp, avg_temp};
  return daily_forecast;
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  std::vector<Forecast> forecasts(weatherData.size());
  std::transform(weatherData.begin(), weatherData.end(), forecasts.begin(), compute_forecast);
  return forecasts;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  std::vector<Forecast> filtered_data(forecastData);
  filtered_data.erase(std::remove_if(filtered_data.begin(), filtered_data.end(), 
                                                            [&](Forecast f){
                                                              return (f.max_temp - f.min_temp) > kMaxTempRequirement && f.avg_temp < uAvgTempRequirement;
                                                            }), 
                                                            filtered_data.end());
  return filtered_data;
}

std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
    std::vector<Forecast> filtered_data(forecastData);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(filtered_data.begin(), filtered_data.end(), g);
    return filtered_data;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
    // Step 1: Convert weather data to Forecast objects
    std::vector<Forecast> forecasts = get_forecasts(weatherData);

    // Step 2: Filter the Forecast data
    forecasts = get_filtered_data(forecasts);

    // Step 3: Shuffle the filtered Forecast data
    forecasts = get_shuffled_data(forecasts);

    // Step 4: Return the processed Forecast data
    return forecasts;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"