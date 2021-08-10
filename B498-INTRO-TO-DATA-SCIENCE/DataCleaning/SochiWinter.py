# Creating Dataframe
from pandas import DataFrame, read_csv
import pandas as pd
import numpy as np


countries_data = ['Russian Fed.', 'Norway', 'Canada', 'United States','Netherlands', 'Germany', 'Switzerland', 'Belarus', # The data
             'Austria', 'France', 'Poland', 'China', 'Korea','Sweden', 'Czech Republic', 'Slovenia', 'Japan',
             'Finland', 'Great Britain', 'Ukraine', 'Slovakia','Italy', 'Latvia', 'Australia', 'Croatia', 'Kazakhstan']

gold = [13, 11, 10, 9, 8, 8, 6, 5, 4, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0]
silver = [11, 5, 10, 7, 7, 6, 3, 0, 8, 4, 1, 4, 3, 7, 4, 2, 4, 3, 1, 0, 0, 2, 2, 2, 1, 0]
bronze = [9, 10, 5, 12, 9, 5, 2, 1, 5, 7, 1, 2, 2, 6, 2, 4, 3, 1, 2, 1, 0, 6, 2, 1, 0, 1]


Sochi_Winter_2014_dataset = list(zip(countries_data,gold,silver,bronze))# Merging the data together


olympic_medal_counts_df = pd.DataFrame(data = Sochi_Winter_2014_dataset, columns = ['Countries', 'Gold', 'Silver', 'Bronze']) # Creating Dataframe


olympic_medal_counts_df.to_csv('SochiWinter2014.csv', index = False) # Writing data to csv file

#Reading File
#Location = r'C:\Users\Edward\Documents\Summer Semester 2021\Data Science\SochiWinter2014.csv'
#pd.read_csv(Location)

# Computing average of bronze medals earned by countries who earned at least one gold medal.

total_bronze = 0
countries_with_gold = 0


gold_column = olympic_medal_counts_df['Gold']
                                              # Seperating gold & bronze column 
bronze_column = olympic_medal_counts_df['Bronze']


got_gold = gold_column > 0 # Creating a boolean array: checks each index in gold_column if > 0 True

for i, value in enumerate(got_gold):
    if got_gold[i] == True:
        countries_with_gold += 1
        total_bronze += bronze_column[i]
        
avg_bronze_at_least_one_gold = total_bronze / countries_with_gold 
print('Average number of bronze medals earned by countries who earned at least one gold medal: ', avg_bronze_at_least_one_gold)

# Computing average number of gold, silver, and bronze medals earned amongst countries who earned at least one medal
#Seperating the data needed
medals = olympic_medal_counts_df[['Gold','Silver','Bronze']]
countries = olympic_medal_counts_df['Countries']

# DataFrame's apply function
avg_medal_count = medals.apply(np.mean, axis = 1)
avg_medal_count.index = countries

# Creating File
avg_medal_count.to_csv("SochiWinter2014Averages.csv")

 #Reading File
Location = r'C:\Users\Edward\Documents\Summer Semester 2021\Data Science\Programmingassignments\SochiWinter2014Averages.csv'
pd.read_csv(Location)

# Assigning 4 point for each gold medal, 2 points for each silver middle, 1 point for each bronze medal 
# and putting it into a series 

points_df = olympic_medal_counts_df[['Gold','Silver','Bronze']].copy(deep = True)

#Multiplying the point values with medals
points_df['Gold'] = np.dot(olympic_medal_counts_df['Gold'],4)
points_df['Silver'] = np.dot(olympic_medal_counts_df['Silver'], 2)
points_df['Bronze'] = np.dot(olympic_medal_counts_df['Bronze'], 1)

# Adding up the rows for total points 
points = points_df.apply(np.sum, axis = 1)

# Merging data
points_data = list(zip(countries, points))

# Creating new dataframe
olympic_points_df = pd.DataFrame(data = points_data , columns =['country_name', 'points'])

olympic_points_df
