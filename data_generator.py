def process_large_file(file_path):
    with open(file_path, 'r') as file:
        next(file)  # Skip the header line
        next(file)  # Skip the separator line
        for line in file:
            year, rainfall = line.strip().split()
            average_rainfall = float(rainfall)
            yield average_rainfall

# Specify the path to the large file
file_path = 'large_file.txt'

# Create a generator object by calling the process_large_file() function
data_generator = process_large_file(file_path)

# Perform calculations on the average rainfall values
total_sum = 0.0
for _ in range(10):
    average_rainfall = next(data_generator)
    total_sum += average_rainfall
print("Total sum:", total_sum)
