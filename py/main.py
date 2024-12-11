# Put in package/messages directory and run, output is in sensitive.txt, send it to Discord support explaining it's a list of sensitive messages you'd like to be deleted.
import os
import json

channels_messages = {}
messages_dir = os.path.dirname(__file__)

# Get all directories from current path
channels = [
	channel
	for channel in os.listdir(messages_dir)
	if os.path.isdir(f"{messages_dir}/{channel}")
]

# Add all messages from json to a dictionary
for channel in channels:
	messages_file = open(f"{messages_dir}/{channel}/messages.json", encoding="utf8")

	messages = json.loads(messages_file.read())
	messages = [str(message["ID"]) for message in messages]

	# Add non-empty channels
	if messages:
		channels_messages[channel] = messages
		
	messages_file.close()

# Write each message with its channel ID and message ID in the new format
all = open(messages_dir + "/sensitive.csv", "w", encoding="utf8")

for channel_id, messages in channels_messages.items():
	for message_id in messages:
		all.write(f"{channel_id},{message_id}\n")  # Write channel ID and message ID on the same line, then newline
	all.write("\n")
all.close()
