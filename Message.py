import discord
from discord.ext import commands
import serial
import time

s = serial.Serial('COM5', 9600)

client = discord.Client()

@client.event
async def on_message(message):
    if message.author == client.user:
        return
    #Sends message if user types "message bot" then sends text
    if message.content.startswith('message bot'):
        await message.channel.send('What do you want to say')
        text = await client.wait_for('message')
        print (text.content)
        await message.channel.send('{}: {}'.format(message.author, text.content))
        if text.content:
            s.write(str.encode(text.content))
            await message.channel.send('Message sent')

client.run('')
