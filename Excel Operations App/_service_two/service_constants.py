entry_message = """ Welcome to the change detection service. This service compares two excel files and creates a report that shows the changed cells. Here are the steps to be followed for this service:

1. Select the first excel file and the sheet. (This will be the "old" records)
2. Select the second excel file and the sheet. (This will be the "new" records)
3. Select the unique key column. This column should exist in both files and should be unique per row.
4. Select the columns to be compared. These columns should exist in both files. The unique key column will not be compared.
5. Click "Save Selected Columns" to save the selected columns.
6. Click "Compare" to compare the two files. This will create a new excel file with the changes.

File will be opened automatically, but also will be saved in the outputs/detect_changes folder.
"""