elementary_particles = []
	
with open('particle_data.txt', 'r') as file:
    for line in file:
        line = line.strip().replace("'", "")  # Remove single quotes and leading/trailing whitespace
        line = line.split(",")  # Split the line into attribute-value pairs	        
        particle_data = {}
        for item in line:
            item = item.strip()  # Remove leading/trailing whitespace
            key, value = item.split(":", 1)  # Split each item into key and value (limiting to 1 split)
            particle_data[key.strip()] = value.strip()
        elementary_particles.append(particle_data)
	
	# Print the particle data in tabular format
print("Name        | Type   | Charge     | Mass")
print("-----------------------------------------------------------")
for particle in elementary_particles:
    name = particle.get('name', '')
    particle_type = particle.get('type', '')
    charge = particle.get('charge', '')
    mass = "{:.2f}".format(float(particle.get('mass', ''))) if particle.get('mass', '').replace('.', '', 1).isdigit() else particle.get('mass', '')
    
    print("{:<12}| {:<7}| {:<11}| {:0>1} |".format(name, particle_type, charge, mass))
