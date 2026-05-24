def check_result(average_marks):
    """
    Function to determine if a student passed or failed.
    Requirement: Uses at least one function.
    """
    # Assuming a passing average is 50 or above
    if average_marks >= 50:
        return "PASSED"
    else:
        return "FAILED"

def main():
    print("=== Student Result Management System ===")
    
    # Requirement: Uses a loop to allow multiple students to be entered
    while True:
        print("\n--- Enter Student Details ---")
        name = input("Enter Student Name: ")
        
        # Requirement: Accepts a student's name and marks for 3 subjects
        try:
            sub1 = float(input("Enter marks for Subject 1: "))
            sub2 = float(input("Enter marks for Subject 2: "))
            sub3 = float(input("Enter marks for Subject 3: "))
        except ValueError:
            print("Invalid input! Please enter numerical values for marks.")
            continue
        
        # Requirement: Calculates the total and average
        total_marks = sub1 + sub2 + sub3
        average_marks = total_marks / 3
        
        # Determine status using the function
        status = check_result(average_marks)
        
        # Requirement: Displays whether the student passed or failed along with stats
        print("\n--- Student Result Summary ---")
        print(f"Student Name : {name}")
        print(f"Total Marks  : {total_marks:.2f}")
        print(f"Average Marks: {average_marks:.2f}")
        print(f"Final Status : {status}")
        print("------------------------------")
        
        # Check if the user wants to continue or exit the loop
        choice = input("\nDo you want to enter another student? (yes/no): ").strip().lower()
        if choice not in ['yes', 'y']:
            print("\nExiting system. Thank you!")
            break

if __name__ == "__main__":
    main()