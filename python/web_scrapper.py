from requests import get
from requests.exceptions import RequestException
from bs4 import BeautifulSoup
from sys import exit
import time
import argparse

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT x.y; Win64; x64; rv:10.0) Gecko/20100101 Firefox/73'}

def get_url(url):
    print(f'Getting url: {url}')
    try:
        return get(url, headers)
    except RequestException as e:
        print(f'ERROR: {e}')
        exit(-1)

def get_soup(response):
    print(f'Parsing html response')
    return BeautifulSoup(response.text, 'html.parser')

def get_img_src(soup):
    print('Getting images links')
    img_srcs = []
    for item in soup.find_all('img'):
        if item.has_attr('src'):
            img_srcs.append(item.attrs['src'])
    return img_srcs

def save_images(soup):
    print('Saving images from page')
    img_srcs = get_img_src(soup)
    for i, src in enumerate(img_srcs):
        try:
            img = get(src, headers)
            with open(f'image_{i}.png', 'wb') as f:
                print(f"Saving image {src.strip('https://')}")
                f.write(img.content)
        except RequestException as e:
            print(f'Error: {e}')
            continue

def main(args):
    url = args.url if 'http' in args.url else 'https://' + args.url
    soup = get_soup(get_url(url))
    save_images(soup)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Scrap some webs!')
    parser.add_argument('-u', '--url', help='url to be scrapped', required=True)
    main(parser.parse_args())
