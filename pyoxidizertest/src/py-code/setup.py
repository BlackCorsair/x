from setuptools import setup, find_packages


setup(name='greeter',
      version='1.0',
      description='greeter package for testing',
      packages=find_packages(),
      test_suites="nose.collector",
      test_dependencies=['nose']
)