🌟 Inventory Management System

Welcome to this simple and intuitive C++ command-line tool designed to help you manage your inventory with ease! Whether you're running a small shop, organizing a warehouse, or just keeping track of your personal collection, this program makes it easy to add items, view your stock, and calculate the total value of everything you’ve got.

✨ Features

Here’s what makes this tool awesome:
Add Items: Quickly enter details for new items, including:
Name: What’s the item called?
Unique Item Code: No duplicates allowed (we’ll check for you!).
Quantity: Must be zero or more.
Price: Keep it positive, no negative prices!
No Duplicate Codes: The system ensures every item code is unique.
View Inventory: See all your items in a clean, tabular format, including a Total Price (Quantity × Price) for each item.
Total Inventory Value: Get the grand total value of all items in one go.
Data Persistence: All your data is saved to a file (Inventory.txt) so nothing gets lost when you close the program.

🖥️ How to Use It

Run the program, and you’ll be greeted with a friendly menu offering these options:
Add an Item: Enter details for a new item.
Show All Items: View all your items in a neat table.
See Total Inventory Value: Check the total worth of your inventory.
Exit: Done for now? This closes the program.

📂 Data Storage

All your inventory data is stored in a file called Inventory.txt in the following format:
ItemName,ItemCode,Quantity,Price
This ensures your data is safe and ready for the next time you run the program.
