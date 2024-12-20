TEMPLATE = subdirs
SUBDIRS += app plugin/MyWonderfulPlugin

# Aggiungi la dipendenza tra app e plugin
app.depends = plugin/MyWonderfulPlugin
