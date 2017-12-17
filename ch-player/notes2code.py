import json
import sys
import os

"""
{
    'song_name': 'name',
    'notes': [],
    'lens': []
}
"""


def convert(source_file, destination_file=None):
    with open(source_file, 'r') as file:
        contents = file.read()

    d = json.loads(contents)
    if destination_file is None:
        path, filename = os.path.split(source_file)
        destination_file = os.path.join(path, 'result_{}'.format(filename))

    result = ''
    with open(destination_file, 'w') as file:
        file.write(result)


def convert_dict_to_string(dct):
    result = '''
namespace {name}{{
    int freqs[] = {{ {freqs} }};
    int lens[] = {{ {lens} }};
    const int len = {len};
}}
'''.format(name=dct['song_name'], freqs=', '.join(dct['nuty']), lens=', '.join([str(w) for w in dct['wagi']]), len=len(dct['nuty']))
    return result

if __name__ == '__main__':
	print(convert_dict_to_string({
		'song_name': 'example',
		'nuty': ['c1', 'd2', 'd4'],
		'wagi': [2, 4, 8]
	}))