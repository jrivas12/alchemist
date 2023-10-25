def read_elements_data(file_name):
    with open(file_name, 'r') as file:
        lines = file.readlines()

    elements = []
    headers = lines[0].strip().split('\t')
    for line in lines[1:]:
        data = line.strip().split('\t')
        element = dict(zip(headers, data))
        elements.append(element)

    return elements

def print_elements_table(elements, file_name):
    headers = elements[0].keys()
    column_widths = [len(header) for header in headers]

    # Adjust column widths based on data
    for element in elements:
        for header in headers:
            if header in element:
                column_widths[list(headers).index(header)] = max(column_widths[list(headers).index(header)], len(element[header]))

    # Print file name
    print(f"Data from file: {file_name}")
    print()

    # Print headers
    header_line = '|'.join(format(header, f' ^{width}') for header, width in zip(headers, column_widths))
    separator_line = '-' * (sum(column_widths) + len(column_widths) * 3 - 1)
    print(header_line)
    print(separator_line)

    # Print rows
    for element in elements:
        row = [format(element.get(header, ''), f' <{width}') for header, width in zip(headers, column_widths)]
        print('|'.join(row))

file_name = 'elements_data.txt'
elements = read_elements_data(file_name)
print_elements_table(elements, file_name)
