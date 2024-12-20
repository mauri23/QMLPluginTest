TEMPLATE = subdirs
SUBDIRS += app plugins/MyWonderfulPlugin

# Aggiungi la dipendenza tra app e plugin
app.depends = plugins/MyWonderfulPlugin
