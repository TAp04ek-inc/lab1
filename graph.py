#!/usr/bin/python3
import sys
import os
import plotly.express as px
import pandas

if len(sys.argv) != 2:
    print("This script takes only one argument")
    exit(0)

filename = sys.argv[1]

file = open(filename,"r")

graph = []

while file.tell() < os.path.getsize(filename):
    line = file.readline()
    entry = line.split(',')
    graph.append([int(entry[0]), int(entry[1])])


df = pandas.DataFrame(graph, columns = ["Time", "ArraySize"])

fig = px.line(df, x="Time", y="ArraySize", title='Life expectancy in Canada')
fig.update_layout(
    width = 1920,
    height = 1080,
    title = "Benchmark Results"
)
fig.write_image(filename.split('.')[0] + ".png")
