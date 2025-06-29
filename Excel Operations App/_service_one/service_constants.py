
entry_message = """Welcome to the forecast comparison service. This service will create a report that compares the forecast columns of the two files. Here are the steps to use this service:

1. Select the first excel and the sheet.
2. Select the ID column that will be used to match the two files.
3. Select the forecast column in the first file.
4. Select any additional columns that you want to include in the report.
5. Select the second excel and the sheet.
6. Select the ID column that will be used to match the two files.
7. Select the forecast column in the second file.
8. Click "Confirm Inputs". Check if the selections align with your expectations.
9. Click "Analyse". This will create a report that compares the forecast columns of the two files.

After pushing the analyse button, the service will take a few seconds to process the data. After this the file will automatically open. It will also be saved in the outputs folder.

NOTE: The service assumes there is a column exactly named "Subregion" in the first file, if that is not the case you may need to rename the existing subregion or create such a column if there is none. DO NOT add "Subregion" as an extra column.
"""