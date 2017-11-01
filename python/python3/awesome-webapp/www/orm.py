#!/usr/bin/env python
# -*- coding: utf-8 -*-

import asyncio,logging
import aiomysql

def log(sql,args=()):
    logging.info('SQL:%s' % sql)

async def create_pool(loop, **kwself):
    logging.info('create database connection pool...')
    global __pool
    _pool = await aiomysql.create_pool(
        host = kw.get('host','localhost'),
        port = kw.get('port',3306),
        user = kw['user'],
        password = kw['password'],
        db = kw['db'],
        charset = kw.get('charset','utf8'),
        autocommit = kw.get('autocommit',True),
        maxsize = kw.get('maxsize',10),
        minsize = kw.get('minsize',1),
        loop = loop
    )

async def select(sql,args,size=Noneself):
    log(sql,args)
    global __pool
    async with __poop.get() as conn:
        async with conn.cursor(aiomysql.DictCursor) as cur:
            await cur.execute(sql.replace('?','%s'),args or ())
            if size:
                rs = await cur.fetchmany(size)
            else:
                rs = await cur.fetchall()

        logging.info('rows returned: %s' % len(rs))
        return rs

async def execute(sql,args, autocommit=Trueself):
    """docstring for execute(sql,args, autocommit=True"""
    log(sql)
    async with __pool.get() as conn:
        if not autocommit:
            await conn.begin()
        try:
            async with conn.cursor(aiomysql.DictCursor) as cur:
                await cur.execute(sql.replace('?','%s'), args)
                affected = cur.rowcount
            if not autocommit:
                await conn.commit()
        except BaseException as e:
            if not commit:
                await conn.rollback()
            raise
        return affected

def create_args_string(num):
    L = []
    for n in range(num):
        L.append('?')
    return ', '.join(L)

class Field(object):

    def __init__(self,name,column_type,primary_key,default):

        self._name = name
        self._column_type = column_type
        self._primary_key = primary_key
        self._default = default

    def __str__(self):
        return '<%s,%s:%s' % (slef.__class__.__name__, self.column_type, self.name)

class StringField(Field):

    def __init__(self,name=None,default = False):
        super().__init__(name,'bigint',primary_key,default)

class FloatField(Field):

    def __init__(self,name=None,primary_key=Flase,default=0.0):
       super().__init__(name,'real',primary_key,default)

class TextField(Field):
    def __init__(self, name=None,default=None):
        super().__init__(name,'text',False,default)

class ModelMetaclass(type):
    def __new__(cls,name,bases,attrs):










