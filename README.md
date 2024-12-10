# sanitize-discord-messages

## Usage 

### Retrieve the message list

#### Request discord package
    Go to discord settings -> Privacy & Safety -> Request all of my data (to speed up the process, choose only messages)

#### Place the script in the correct directory
    Download the python script and place it into the messages folder

#### Run the script
for python:
```bash
python3 main.py
```
for c++:
compile with 
```bash
g++ main.cpp -o compilerOutput
```
run with ```./compilerOutput``` (with the .exe for windows) or double click the executable on windows

### Contact Discord support

#### Go to the correct discord team
Their [privacy team](https://support.discord.com/hc/en-us/requests/new?ticket_form_id=4750383925911) (Discord support site -> Submit a request -> Contact discord privacy -> Delete your personal information)

#### The ticket description
Ask them that you have sensitive messages that you can't access, append the output of the script in the attachments and tell them that it's in an accessible for them format with the proper channel and message ids

> [!NOTE]  
> Incase they reply negatively, repeat the previous step but reworded or with extra requirements they might ask. 


## Disclaimer

* This may change in the future, with the recent usage of this method they started taking more time to process your request.


## Doesn't work?

In the case it changed, please make an issue with their replies and I will look into it. (For your own safety dont append the messages list!)


## Licenses

This project is licensed under the [GPLv3](https://www.gnu.org/licenses/gpl-3.0.html) License. However, it uses the following third-party package(s) that are licensed under the [MIT](https://opensource.org/license/MIT) License:
- [json](https://github.com/nlohmann/json) - Copyright (c) [2024] [Nlohmann]



