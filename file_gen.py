import os

# Specify the directory to read files from
directory = '/Users/spartan/Employee-Payroll-Management-System'

# Name of the output file
output_filename = '/Users/spartan/Employee-Payroll-Management-System/output_text.txt'

# List of file extensions to include
extensions = ('.cpp', '.h', '.ui')

def safe_read(file_path):
    """Attempt to read a file with multiple encodings or treat as binary if it fails."""
    encodings = ['utf-8', 'utf-16', 'iso-8859-1']  # Common encodings
    for encoding in encodings:
        try:
            with open(file_path, 'r', encoding=encoding) as file:
                return file.read()
        except UnicodeDecodeError:
            continue
    # If all text encodings fail, try reading the file as binary
    try:
        with open(file_path, 'rb') as file:
            return file.read().decode('latin1')
    except Exception as e:
        return f"Error reading file as binary: {str(e)}"

# Create an output file and open it in write mode
with open(output_filename, 'w') as output_file:
    # Walk through all files and directories in the specified directory
    for root, dirs, files in os.walk(directory):
        for filename in files:
            if filename.endswith(extensions):
                # Construct the full file path
                file_path = os.path.join(root, filename)
                # Write the file name to the output file
                output_file.write(f"Filename: {filename}\n")
                # Read the contents of the file safely
                contents = safe_read(file_path)
                # Write the contents to the output file
                output_file.write(contents + "\n\n")

print("Data has been combined into", output_filename)
